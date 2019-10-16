/*
    AVL tree 
    ------------------
    AVL tree is a self-balancing binary search tree. In an AVL tree,
    the heights of two child subtrees of any node differ by at most
    one. When the height difference becomes too big(> 1), the tree
    rebalances to maintain the balanced structure.

    Unlike binary search trees, search, insertion and removal on
    an AVL tree will always be O(log n).
*/

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <functional>
#include <array>
#include <vector>
#include <iostream>

#include "avl_node.hpp"

class AVLTree {
public:
    using NodeHandler = std::function<void(AVLNode*)>;
    using ThreeLinkedNodes = std::array<AVLNode*, 3>;
    enum TraverseOrder { PRE, IN, POST };
    AVLTree();
    AVLTree(const std::initializer_list<int>& il) 
        : AVLTree() {
        for (int i : il) insert(i);
    }
    void insert(int);
    void remove(int);

    AVLNode* search(int value);
    bool exists(int value);

    void traverse(NodeHandler&, TraverseOrder);
    void traverse(NodeHandler&, TraverseOrder, AVLNode*);

    void traverse(NodeHandler&&, TraverseOrder);
    void traverse(NodeHandler&&, TraverseOrder, AVLNode*);

    int get_size() { return size; }
    AVLNode* get_root() { return rootParent->leftChild; }
    void set_root(AVLNode* newRoot) { rootParent->attach_left_child(newRoot); }
private:
    AVLNode* rootParent;
    int size;

    enum ImbalanceType {
        BALANCED,
        LEFT_LEFT,
        RIGHT_RIGHT,
        LEFT_RIGHT,
        RIGHT_LEFT,
    };

    bool isImbalanced(AVLNode*);

    void handle_first_insert(int);
    AVLNode* bst_insert(int);
    AVLNode* find_place_to_insert(int);
    AVLNode* rebalance_after_insert(AVLNode*);
    ThreeLinkedNodes get_segment_imbalanced_by_insert(AVLNode*);
    ImbalanceType get_imbalance_type_for_insert(ThreeLinkedNodes&);

    void remove_node(AVLNode*);
    void handle_last_remove();
    AVLNode* bst_remove(AVLNode*);
    AVLNode* find_imbalanced_ancestor(AVLNode*);
    ThreeLinkedNodes get_segment_imbalanced_by_remove(AVLNode*, ImbalanceType);
    AVLNode* rebalance_after_remove(AVLNode*);
    ImbalanceType get_imbalance_type_for_remove(AVLNode* node);


    AVLNode* rotate_to_rebalance(ThreeLinkedNodes&, ImbalanceType);
    AVLNode* rotate_left(AVLNode*);
    AVLNode* rotate_right(AVLNode*);

    AVLNode* detach_from_tree(AVLNode*);

    AVLNode* predecessor_node(AVLNode* node);
    AVLNode* successor_node(AVLNode* node);
};

AVLTree::AVLTree() : rootParent(new AVLNode(0)), size(0) {}

/*
    Insert
    ------
    This first performs the normal binary search tree insertion,
    (see explanation at BinarySearchTree::insert). Then, it traverses
    upwards through the ancestors of the newly inserted node, checking
    if any node has become imbalanced. If an imbalanced node is found,
    the function performs a series of "rotations" to rebalance the tree.
    The rotations performed are based on the "type" of imbalance.

    Time complexity
    ---------------
    O(log n) (In contrast to normal binary search tree, which is O(log n)
    only in the average case)

    Space complexity
    ----------------
    O(1)
*/
void AVLTree::insert(int value) {
    if (size == 0) {
        handle_first_insert(value);
        return;
    } 
    AVLNode* insertedNode = bst_insert(value);
    if (insertedNode != nullptr) {
        rebalance_after_insert(insertedNode);
        ++size;
    }
}

/*
    Remove
    ------
    This traverses the tree to find the node with the give value. Then,
    peforms standard binary search tree node removal. After that, it runs
    upwards through the ancestors of the newly inserted node, checking
    if any node has become imbalanced. If an imbalanced node is found,
    the function performs a series of "rotations" to rebalance the tree.
    The rotations performed are based on the "type" of imbalance. Unlike
    insertion, more than one ancestor node may become unbalanced, so
    checks must be done all the way to the root.

    Time complexity
    ---------------
    O(log n) (In contrast to normal binary search tree, which is O(log n)
    only in the average case)

    Space complexity
    ----------------
    O(1)
*/
void AVLTree::remove(int value) {
    AVLNode* doomedNode = search(value);
    remove_node(doomedNode);
}

/*
    Search
    ------
    This traverses the tree to find the presence of number in the tree. At each
    node, it checks if the node has a value lesser than itself, if so it goes
    to its left subtree. If it is greater it goes to the right subtree. When it
    node with the matching value, it returns the node. If no node with a given
    value is found, it returns a nullptr. 
    
    Time complexity
    ---------------
    O(log n)

    Space complexity
    ----------------
    O(1)

*/
AVLNode* AVLTree::search(int value) {
    AVLNode* candidate = get_root();
    while (candidate != nullptr) {
        if (value < candidate->value) {
            candidate = candidate->leftChild;
        }
        else if (value > candidate->value) {
            candidate = candidate->rightChild;
        }
        else {
            break;
        }
    }
    return candidate;
}

bool AVLTree::exists(int value) {
    return search(value) != nullptr;
}

void AVLTree::traverse(
    AVLTree::NodeHandler& function, AVLTree::TraverseOrder order) {
    traverse(function, order, get_root());
}

void AVLTree::traverse(
    AVLTree::NodeHandler& function,
    AVLTree::TraverseOrder order,
    AVLNode* root) {
    if (root == nullptr) return;
    if (order == PRE) {
        function(root);
    }
    traverse(function, order, root->leftChild);
    if (order == IN) {
        function(root);
    }
    traverse(function, order, root->rightChild);
    if (order == POST) {
        function(root);
    }
}

void AVLTree::traverse(
    AVLTree::NodeHandler&& function, AVLTree::TraverseOrder order) {
    traverse(std::forward<NodeHandler&&>(function), order, get_root());
}

void AVLTree::traverse(
    AVLTree::NodeHandler&& function,
    AVLTree::TraverseOrder order,
    AVLNode* root) {
    if (root == nullptr) return;
    if (order == PRE) {
        function(root);
    }
    traverse(std::forward<NodeHandler>(function), order, root->leftChild);
    if (order == IN) {
        function(root);
    }
    traverse(std::forward<NodeHandler>(function), order, root->rightChild);
    if (order == POST) {
        function(root);
    }
}

void AVLTree::handle_first_insert(int value) {
    auto newNode = new AVLNode(value);
    rootParent->attach_left_child(newNode);
    size = 1;
}

AVLNode* AVLTree::bst_insert(int value) {
    auto newNode = new AVLNode(value);
    AVLNode* parentToAcceptNewNode = find_place_to_insert(value);
    if (parentToAcceptNewNode == nullptr) {
        return nullptr;
    }
    if (value <= parentToAcceptNewNode->value) {
        parentToAcceptNewNode->attach_left_child(newNode);
    }
    else {
        parentToAcceptNewNode->attach_right_child(newNode);
    }
    return newNode;
}

AVLNode* AVLTree::find_place_to_insert(int value) {
    auto parentToAcceptNewNode = get_root();
    int parentValue = parentToAcceptNewNode->value;
    while (true) {
        if (value <= parentValue) {
            if (parentToAcceptNewNode->leftChild == nullptr) {
                return parentToAcceptNewNode;
            }
            else {
                parentToAcceptNewNode = parentToAcceptNewNode->leftChild;
                parentValue = parentToAcceptNewNode->value;
            }
        }
        else {
            if (parentToAcceptNewNode->rightChild == nullptr) {
                return parentToAcceptNewNode;
            }
            else {
                parentToAcceptNewNode = parentToAcceptNewNode->rightChild;
                parentValue = parentToAcceptNewNode->value;
            }
        }
    }
    return nullptr; 
}

AVLTree::ThreeLinkedNodes AVLTree::get_segment_imbalanced_by_insert(
    AVLNode* origin) {

    AVLTree::ThreeLinkedNodes ret{ origin, nullptr, nullptr };

    while (ret[0] != rootParent) {
        if (isImbalanced(ret[0]))
            break;
        ret[2] = ret[1];
        ret[1] = ret[0];
        ret[0] = ret[0]->parent;
    } 

    return ret;
}

AVLTree::ImbalanceType AVLTree::get_imbalance_type_for_insert(
    AVLTree::ThreeLinkedNodes& segment) {
    auto imbalancedRoot = segment[0],
         imbalancedChild = segment[1],
         imbalancedGrandChild = segment[2];

    if (imbalancedRoot == rootParent) {
        return ImbalanceType::BALANCED;
    }
    if (imbalancedRoot->leftChild == imbalancedChild) {
        if (imbalancedChild->leftChild == imbalancedGrandChild) {
            return ImbalanceType::LEFT_LEFT;
        }
        else {
            return ImbalanceType::LEFT_RIGHT;
        }
    }
    else {
        if (imbalancedChild->rightChild == imbalancedGrandChild) {
            return ImbalanceType::RIGHT_RIGHT;
        }
        else {
            return ImbalanceType::RIGHT_LEFT;
        }
    }

    return ImbalanceType::BALANCED;
}

AVLNode* AVLTree::rotate_left(AVLNode* oldRoot) { 
    auto newRoot = oldRoot->rightChild;
    auto oldRootParent = oldRoot->parent;

    oldRootParent->replace_child(oldRoot, newRoot);

    // node(subtree) that goes from being left child of 
    // newRoot to right child of old root
    auto sideSwitchingNode = newRoot->leftChild;
    newRoot->attach_left_child(oldRoot);
    oldRoot->attach_right_child(sideSwitchingNode);
    return newRoot;
}

AVLNode* AVLTree::rotate_right(AVLNode* oldRoot) { 
    auto newRoot = oldRoot->leftChild;
    auto oldRootParent = oldRoot->parent;

    oldRootParent->replace_child(oldRoot, newRoot);

    auto sideSwitchingNode = newRoot->rightChild;
    newRoot->attach_right_child(oldRoot);
    oldRoot->attach_left_child(sideSwitchingNode);
    return newRoot;
}

AVLNode* AVLTree::rotate_to_rebalance(
    AVLTree::ThreeLinkedNodes& segment,
    AVLTree::ImbalanceType imbalanceType) {
    
    switch (imbalanceType)
    {
    case ImbalanceType::LEFT_LEFT:
        return rotate_right(segment[0]); 
        // return segment[1];

    case ImbalanceType::LEFT_RIGHT:
        rotate_left(segment[1]);
        return rotate_right(segment[0]);
        // return segment[2];

    case ImbalanceType::RIGHT_RIGHT:
        return rotate_left(segment[0]);
        // return segment[1];

    case ImbalanceType::RIGHT_LEFT:
        rotate_right(segment[1]);
        return rotate_left(segment[0]);
        // return segment[2];

    case ImbalanceType::BALANCED:
        return nullptr;

    default:
        break;
    }
    return nullptr;
}

AVLNode* AVLTree::rebalance_after_insert(AVLNode *insertedNode) {
    auto segment = get_segment_imbalanced_by_insert(insertedNode);
    auto imbalanceType = get_imbalance_type_for_insert(segment);

    return rotate_to_rebalance(segment, imbalanceType);
}

void AVLTree::handle_last_remove() {
    auto lastNode = rootParent->detach_left_child();
    delete lastNode;
    size = 0;
}

AVLNode* AVLTree::detach_from_tree(AVLNode* node) {
    if (node->parent == nullptr) {
        throw std::runtime_error("Root node must not be detached from tree");
    }
    if (node->leftChild != nullptr && node->rightChild != nullptr) {
        throw std::runtime_error("Detaching node with two children");
    }

    AVLNode* nodeParent = node->parent;
    bool nodeIsLeftChildOfParent = nodeParent->isLeftChild(node);
    node->detach_parent();

    auto leftChild = node->detach_left_child();
    auto rightChild = node->detach_right_child();

    auto childToAttach = (leftChild == nullptr ? rightChild : leftChild);

    if (nodeIsLeftChildOfParent) {
        nodeParent->attach_left_child(childToAttach);
    }
    else {
        nodeParent->attach_right_child(childToAttach);
    }
    return node;
}

AVLNode* AVLTree::bst_remove(AVLNode* node) {
    if (node == nullptr) return nullptr;

    AVLNode* nodeToDelete = node;
    AVLNode* nodeToReturn = nodeToDelete->parent;

    int childCount = nodeToDelete->child_count();

    if (childCount == 0 || childCount == 1) {
        detach_from_tree(nodeToDelete);
    }
    else {
        nodeToDelete = successor_node(node);
        nodeToReturn = nodeToDelete->parent;
        std::swap(nodeToDelete->value, node->value);
        detach_from_tree(nodeToDelete);
    }

    delete nodeToDelete;
    return nodeToReturn;
}

void AVLTree::remove_node(AVLNode* node) {
    if (node == nullptr) return;

    if (size == 1) { 
        handle_last_remove();
        return;
    }

    AVLNode* nodeToRebalance = bst_remove(node);
    while (nodeToRebalance != rootParent) {
        nodeToRebalance = rebalance_after_remove(nodeToRebalance);
        nodeToRebalance = find_imbalanced_ancestor(nodeToRebalance);
    }
    --size;
}


bool AVLTree::isImbalanced(AVLNode* node) {
    constexpr int MaxAllowedImbalance = 1;
    const int leftChildHeight = AVLNode::get_height(node->leftChild);
    const int rightChildHeight = AVLNode::get_height(node->rightChild);
    const int balance = leftChildHeight - rightChildHeight;
    return std::abs(balance) > MaxAllowedImbalance;
}

AVLNode* AVLTree::rebalance_after_remove(AVLNode* node) {
    if (node == rootParent || !isImbalanced(node)) return node->parent;
    ImbalanceType imbalanceType =
        get_imbalance_type_for_remove(node);

    auto segment = get_segment_imbalanced_by_remove(
        node, imbalanceType);

    return rotate_to_rebalance(segment, imbalanceType);
}

AVLTree::ThreeLinkedNodes AVLTree::get_segment_imbalanced_by_remove(
    AVLNode* node, ImbalanceType imbalancedType) {
    switch (imbalancedType)
    {
    case LEFT_LEFT:
        return { node, node->leftChild, node->leftChild->leftChild };
    
    case LEFT_RIGHT:
        return { node, node->leftChild, node->leftChild->rightChild };
    
    case RIGHT_LEFT:
        return {
            node, node->rightChild, node->rightChild->leftChild };
    case RIGHT_RIGHT:
        return {
            node, node->rightChild, node->rightChild->rightChild };
    default:
        return { nullptr };
    }
}

AVLTree::ImbalanceType AVLTree::get_imbalance_type_for_remove(AVLNode* node) {
    if (!isImbalanced(node)) return ImbalanceType::BALANCED;

    AVLNode* firstBranch = AVLNode::get_longer_branch(node);
    AVLNode* secondBranch = AVLNode::get_longer_branch(firstBranch);

    if (node->isLeftChild(firstBranch) &&
            firstBranch->isLeftChild(secondBranch)) {
        return LEFT_LEFT;
    }
    else if (node->isLeftChild(firstBranch) &&
                firstBranch->isRightChild(secondBranch)) {
        return LEFT_RIGHT;
    }
    else if  (node->isRightChild(firstBranch) &&
                firstBranch->isLeftChild(secondBranch)) {
        return RIGHT_LEFT;
    }
    else if (node->isRightChild(firstBranch) &&
                firstBranch->isRightChild(secondBranch)) {
        return RIGHT_RIGHT;
    }
    return BALANCED;
}

AVLNode* AVLTree::successor_node(AVLNode* node) {
    AVLNode* ret = node->rightChild;
    if (ret == nullptr) return ret;
    while (ret->leftChild != nullptr) {
        ret = ret->leftChild;
    }
    return ret;
}

AVLNode* AVLTree::predecessor_node(AVLNode* node) {
    AVLNode* ret = node->leftChild;
    if (ret == nullptr) return ret;
    while (ret->rightChild != nullptr) {
        ret = ret->rightChild;
    }
    return ret;
}

AVLNode* AVLTree::find_imbalanced_ancestor(AVLNode* node) {
    while (node != rootParent) {
        if (isImbalanced(node)) break;
        node = node->parent;
    }
    return node;
}
#endif // AVL_TREE_HPP