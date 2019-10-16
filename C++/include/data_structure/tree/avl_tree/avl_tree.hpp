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
    AVLTree(const std::initializer_list<int>& il);
    void insert(int);
    void remove(int);

    AVLNode* search(int value);
    bool exists(int value);

    void traverse(NodeHandler&, TraverseOrder);
    void traverse(NodeHandler&, TraverseOrder, AVLNode*);

    void traverse(NodeHandler&&, TraverseOrder);
    void traverse(NodeHandler&&, TraverseOrder, AVLNode*);

    int get_size() { return size; }
    AVLNode* get_root() { return root_parent->left_child; }
    void set_root(AVLNode* new_root) { root_parent->attach_left_child(new_root); }
private:
    AVLNode* root_parent;
    int size;

    enum ImbalanceType {
        BALANCED,
        LEFT_LEFT,
        RIGHT_RIGHT,
        LEFT_RIGHT,
        RIGHT_LEFT,
    };

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
    ImbalanceType get_imbalance_type_for_remove(AVLNode*);


    AVLNode* rotate_to_rebalance(ThreeLinkedNodes&, ImbalanceType);
    AVLNode* rotate_left(AVLNode*);
    AVLNode* rotate_right(AVLNode*);

    AVLNode* detach_from_tree(AVLNode*);

    AVLNode* predecessor_node(AVLNode*);
    AVLNode* successor_node(AVLNode*);
};

AVLTree::AVLTree() : root_parent(new AVLNode(0)), size(0)
{}

AVLTree::AVLTree(const std::initializer_list<int>& il)
    : AVLTree() {
    for (int i : il) insert(i);
}
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
    AVLNode* inserted_node= bst_insert(value);
    if (inserted_node != nullptr) {
        rebalance_after_insert(inserted_node);
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
    AVLNode* doomed_node = search(value);
    remove_node(doomed_node);
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
            candidate = candidate->left_child;
        }
        else if (value > candidate->value) {
            candidate = candidate->right_child;
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
    traverse(function, order, root->left_child);
    if (order == IN) {
        function(root);
    }
    traverse(function, order, root->right_child);
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
    traverse(std::forward<NodeHandler>(function), order, root->left_child);
    if (order == IN) {
        function(root);
    }
    traverse(std::forward<NodeHandler>(function), order, root->right_child);
    if (order == POST) {
        function(root);
    }
}

void AVLTree::handle_first_insert(int value) {
    auto new_node = new AVLNode(value);
    root_parent->attach_left_child(new_node);
    size = 1;
}

AVLNode* AVLTree::bst_insert(int value) {
    auto newNode = new AVLNode(value);
    AVLNode* parent_accepting_new_node = find_place_to_insert(value);
    if (parent_accepting_new_node == nullptr) {
        return nullptr;
    }
    if (value <= parent_accepting_new_node->value) {
        parent_accepting_new_node->attach_left_child(newNode);
    }
    else {
        parent_accepting_new_node->attach_right_child(newNode);
    }
    return newNode;
}

AVLNode* AVLTree::find_place_to_insert(int value) {
    auto parent_accepting_new_node = get_root();
    int parent_value = parent_accepting_new_node->value;
    while (true) {
        if (value <= parent_value) {
            if (parent_accepting_new_node->left_child == nullptr) {
                return parent_accepting_new_node;
            }
            else {
                parent_accepting_new_node = parent_accepting_new_node->left_child;
                parent_value = parent_accepting_new_node->value;
            }
        }
        else {
            if (parent_accepting_new_node->right_child == nullptr) {
                return parent_accepting_new_node;
            }
            else {
                parent_accepting_new_node = parent_accepting_new_node->right_child;
                parent_value = parent_accepting_new_node->value;
            }
        }
    }
    return nullptr; 
}

AVLTree::ThreeLinkedNodes AVLTree::get_segment_imbalanced_by_insert(
    AVLNode* origin) {

    AVLNode* node = origin;
    AVLNode* child = nullptr;
    AVLNode* grandchild = nullptr;
    while (node != root_parent) {
        if (!node->is_balanced())
            break;
        grandchild = child;
        child = node;
        node = node->parent;
    } 

    return { node, child, grandchild };
}

AVLTree::ImbalanceType AVLTree::get_imbalance_type_for_insert(
    AVLTree::ThreeLinkedNodes& imbalanced_segment) {

    auto imbalanced_node = imbalanced_segment[0],
         child = imbalanced_segment[1],
         grandchild = imbalanced_segment[2];

    if (imbalanced_node == root_parent ||
        imbalanced_node->is_balanced()) {
        return ImbalanceType::BALANCED;
    }
    if (imbalanced_node->left_child == child) {
        if (child->left_child == grandchild) {
            return ImbalanceType::LEFT_LEFT;
        }
        else {
            return ImbalanceType::LEFT_RIGHT;
        }
    }
    else {
        if (child->right_child == grandchild) {
            return ImbalanceType::RIGHT_RIGHT;
        }
        else {
            return ImbalanceType::RIGHT_LEFT;
        }
    }

    return ImbalanceType::BALANCED;
}

AVLNode* AVLTree::rotate_left(AVLNode* old_root) { 
    auto new_root = old_root->right_child;
    auto old_root_parent = old_root->parent;

    old_root_parent->replace_child(old_root, new_root);

    // node(subtree) that goes from being left child of 
    // new_root to right child of old root
    auto side_switching_node = new_root->left_child;
    new_root->attach_left_child(old_root);
    old_root->attach_right_child(side_switching_node);
    return new_root;
}

AVLNode* AVLTree::rotate_right(AVLNode* old_root) { 
    auto new_root = old_root->left_child;
    auto old_root_parent = old_root->parent;

    old_root_parent->replace_child(old_root, new_root);

    auto side_switching_node = new_root->right_child;
    new_root->attach_right_child(old_root);
    old_root->attach_left_child(side_switching_node);
    return new_root;
}

AVLNode* AVLTree::rotate_to_rebalance(
    AVLTree::ThreeLinkedNodes& segment,
    AVLTree::ImbalanceType imbalance_type) {
    
    switch (imbalance_type)
    {
    case ImbalanceType::LEFT_LEFT:
        return rotate_right(segment[0]); 

    case ImbalanceType::LEFT_RIGHT:
        rotate_left(segment[1]);
        return rotate_right(segment[0]);

    case ImbalanceType::RIGHT_RIGHT:
        return rotate_left(segment[0]);

    case ImbalanceType::RIGHT_LEFT:
        rotate_right(segment[1]);
        return rotate_left(segment[0]);

    case ImbalanceType::BALANCED:
        return nullptr;

    default:
        break;
    }
    return nullptr;
}

AVLNode* AVLTree::rebalance_after_insert(AVLNode *inserted_node) {
    auto segment = get_segment_imbalanced_by_insert(inserted_node);
    auto imbalance_type = get_imbalance_type_for_insert(segment);

    return rotate_to_rebalance(segment, imbalance_type);
}

void AVLTree::handle_last_remove() {
    auto last_node = root_parent->detach_left_child();
    delete last_node;
    size = 0;
}

AVLNode* AVLTree::detach_from_tree(AVLNode* node) {
    if (node->parent == nullptr) {
        throw std::runtime_error("Root node must not be detached from tree");
    }
    if (node->left_child != nullptr && node->right_child != nullptr) {
        throw std::runtime_error("Detaching node with two children");
    }

    AVLNode* node_parent = node->parent;
    bool node_is_left_child = node_parent->is_left_child(node);
    node->detach_parent();

    auto left_child = node->detach_left_child();
    auto right_child = node->detach_right_child();

    auto child_to_attach = (left_child == nullptr ? right_child : left_child);

    if (node_is_left_child) {
        node_parent->attach_left_child(child_to_attach);
    }
    else {
        node_parent->attach_right_child(child_to_attach);
    }
    return node;
}

AVLNode* AVLTree::bst_remove(AVLNode* node) {
    if (node == nullptr) return nullptr;

    AVLNode* node_to_delete = node;
    AVLNode* node_to_return = node_to_delete->parent;

    int childCount = node_to_delete->child_count();

    if (childCount == 0 || childCount == 1) {
        detach_from_tree(node_to_delete);
    }
    else {
        node_to_delete = successor_node(node);
        node_to_return = node_to_delete->parent;
        std::swap(node_to_delete->value, node->value);
        detach_from_tree(node_to_delete);
    }

    delete node_to_delete;
    return node_to_return;
}

void AVLTree::remove_node(AVLNode* node) {
    if (node == nullptr) return;

    if (size == 1) { 
        handle_last_remove();
        return;
    }

    AVLNode* node_to_rebalance = bst_remove(node);
    while (node_to_rebalance != root_parent) {
        node_to_rebalance = rebalance_after_remove(node_to_rebalance);
        node_to_rebalance = find_imbalanced_ancestor(node_to_rebalance);
    }
    --size;
}

AVLNode* AVLTree::rebalance_after_remove(AVLNode* node) {
    if (node == root_parent || node->is_balanced()) return node->parent;
    ImbalanceType imbalance_type =
        get_imbalance_type_for_remove(node);

    auto segment = get_segment_imbalanced_by_remove(
        node, imbalance_type);

    return rotate_to_rebalance(segment, imbalance_type);
}

AVLTree::ThreeLinkedNodes AVLTree::get_segment_imbalanced_by_remove(
    AVLNode* node, ImbalanceType imbalanced_type) {
    switch (imbalanced_type)
    {
    case LEFT_LEFT:
        return { node, node->left_child, node->left_child->left_child };
    
    case LEFT_RIGHT:
        return { node, node->left_child, node->left_child->right_child };
    
    case RIGHT_LEFT:
        return {
            node, node->right_child, node->right_child->left_child };
    case RIGHT_RIGHT:
        return {
            node, node->right_child, node->right_child->right_child };
    default:
        return { nullptr };
    }
}

AVLTree::ImbalanceType AVLTree::get_imbalance_type_for_remove(AVLNode* node) {
    if (node->is_balanced()) return ImbalanceType::BALANCED;

    AVLNode* first_branch = AVLNode::get_longer_branch(node);
    AVLNode* second_branch = AVLNode::get_longer_branch(first_branch);

    if (node->is_left_child(first_branch) &&
            first_branch->is_left_child(second_branch)) {
        return LEFT_LEFT;
    }
    else if (node->is_left_child(first_branch) &&
                first_branch->is_right_child(second_branch)) {
        return LEFT_RIGHT;
    }
    else if  (node->is_right_child(first_branch) &&
                first_branch->is_left_child(second_branch)) {
        return RIGHT_LEFT;
    }
    else if (node->is_right_child(first_branch) &&
                first_branch->is_right_child(second_branch)) {
        return RIGHT_RIGHT;
    }
    return BALANCED;
}

AVLNode* AVLTree::successor_node(AVLNode* node) {
    AVLNode* ret = node->right_child;
    if (ret == nullptr) return ret;
    while (ret->left_child != nullptr) {
        ret = ret->left_child;
    }
    return ret;
}

AVLNode* AVLTree::predecessor_node(AVLNode* node) {
    AVLNode* ret = node->left_child;
    if (ret == nullptr) return ret;
    while (ret->right_child != nullptr) {
        ret = ret->right_child;
    }
    return ret;
}

AVLNode* AVLTree::find_imbalanced_ancestor(AVLNode* node) {
    while (node != root_parent) {
        if (!node->is_balanced()) break;
        node = node->parent;
    }
    return node;
}
#endif // AVL_TREE_HPP