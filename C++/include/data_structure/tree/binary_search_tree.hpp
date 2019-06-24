/*
    Binary Search Tree
    ------------------
    A graph data structure where each node has a unidirectional path to at most
    two node, none of which are itself or its predecessors, i.e the graph is
    acyclic. The first node is called the root node. Another important feature
    of this tree is that each node has values lesser than or equal to itself in
    the left subtree and values greater than or equal to itself in the right
    subtree.
*/

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <climits>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

const int INF = INT_MAX;

struct Node {
    int value;
    Node* left_child;
    Node* right_child;
};

Node* get_node();

class BinarySearchTree {
private:
    Node* root;

    void remove_current_node(Node* current, Node* parent);
    void traversal_inorder_helper(Node* tree, vector<int>& values);
    void traversal_preorder_helper(Node* tree, vector<int>& values);
    void traversal_postorder_helper(Node* tree, vector<int>& values);

public:

    BinarySearchTree();
    bool insert(int);
    bool remove(int);
    bool search(int);
    vector<int> traversal_inorder_recursive();
    vector<int> traversal_inorder_iterative();
    vector<int> traversal_preorder_recursive();
    vector<int> traversal_preorder_iterative();
    vector<int> traversal_postorder_recursive();
    vector<int> traversal_postorder_iterative();
};

Node* get_node() {
    Node* newNode = new Node();
    newNode->left_child = newNode->right_child = nullptr;

    return newNode;
}

BinarySearchTree::BinarySearchTree() {
    root = get_node();
    root->value = INF;
}

/*
    Insert
    ------
    This traverses the tree to find the right spot to insert the newly given
    value. At each node, it checks if the node has a value lesser than or equal
    to itself, if so it goes to its left subtree. Otherwise it goes to the right
    subtree. When it meets an end point i.e. NULL it inserts the new Node along
    with the new value

    Time complexity
    ---------------
    Average case : O(log n), where n is the number of nodes in the tree
    Worst case : O(n)

    Space complexity
    ----------------
    O(1)
*/
bool BinarySearchTree::insert(int value) {
    // If first insertion, replace the value of the already created node
    if (root->value == INF) {
        root->value = value;
        return true;
    }

    Node* current = root;
    Node* newNode = get_node();

    // Failed to allocate memory to a new node
    if (newNode == nullptr) {
        return false;
    }

    while (true) {
        if (value <= current->value) {
            if (current->left_child == nullptr) {
                current->left_child = newNode;
                current->left_child->value = value;
                return true;
            } else {
                current = current->left_child;
            }
        } else {
            if (current->right_child == nullptr) {
                current->right_child = newNode;
                current->right_child->value = value;
                return true;
            } else {
                current = current->right_child;
            }
        }
    }
}

/*
    Remove
    ------
    This traverses the tree to find the given value. At each node, it checks if
    the node has a value equal to the given value, if so it finds the inorder
    successor of the node, and replaces the value to be deleted with that number.
    Otherwise, it searches in the left subtree if the value is smaller than
    node value and it searches the right subtree if the value is larger.

    Time complexity
    ---------------
    Average case : O(log n), where n is the number of nodes in the tree
    Worst case : O(n)

    Space complexity
    ----------------
    O(1)
*/
bool BinarySearchTree::remove(int value) {
    // If tree is empty remove is unsuccessful
    if (root->value == INF) {
        return false;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (true) {
        if (value == current->value) {
            remove_current_node(current, parent);
            return true;
        } else {
            parent = current;

            if (current->value < value) {   // Search in the right subtree
                current = current->right_child;
            } else {                        // Search in the left subtree
                current = current->left_child;
            }

            if (current == nullptr) {
                return false;
            }
        }
    }
}
void BinarySearchTree::remove_current_node(Node* current, Node* parent) {
    Node* toBeDeleted;
    Node* successor;
    Node* successorParent = nullptr;

    // If current node has no children
    if (current->right_child == nullptr && current->left_child == nullptr) {
        if (parent == nullptr) {
            current->value = INF;
        } else {
            if (parent->left_child == current) {
                parent->left_child = nullptr;
            } else {
                parent->right_child = nullptr;
            }

            delete current;
        }
    } else if (current->right_child == nullptr) {
        toBeDeleted = current->left_child;
        current->value = current->left_child->value;
        current->right_child = current->left_child->right_child;
        current->left_child = current->left_child->left_child;
        delete toBeDeleted;
    } else {
        successor = current->right_child;
        successorParent = nullptr;

        while (successor->left_child != nullptr) {
            successorParent = successor;
            successor = successor->left_child;
        }

        if (successorParent == nullptr) {
            current->right_child = successor->right_child;
        } else {
            successorParent->left_child = successor->right_child;
        }
        current->value = successor->value;
        delete successor;
    }
}

/*
    Search
    ------
    This traverses the tree to find the presence of number in the tree. At each
    node, it checks if the node has a value lesser than itself, if so it goes
    to its left subtree. If it is greater it goes to the right subtree. When it
    node with the matching value or reaches the end of the tree it returns either
    true or false appropriately.

    Time complexity
    ---------------
    Average case : O(log n), where n is the number of nodes in the tree
    Worst case : O(n)

    Space complexity
    ----------------
    O(1)
*/
bool BinarySearchTree::search(int value) {
    Node* current = root;

    while (true) {
        if (value < current->value) {
            if (current->left_child == nullptr) {
                return false;
            } else {
                current = current->left_child;
            }
        } else if (value > current->value) {
            if (current->right_child == nullptr) {
                return false;
            } else {
                current = current->right_child;
            }
        } else {
            return true;
        }
    }
}

/*
    Inorder traversal
    -----------------
    This Algorithm visits and displays each node in the following order starting
    with the root node. The Left subtree, followed by Parent, followed by the
    Right subtree. This traversal gives the values stored in the tree in a
    sorted order.

    Time complexity
    ---------------
    Average case : O(n), where n is the number of nodes in the tree
    Worst case : O(n)

    Space complexity
    ----------------
    O(n), where n is the number if nodes in the tree
*/
void BinarySearchTree::traversal_inorder_helper(Node* tree, vector<int>& values) {
    if (tree == nullptr or tree->value == INF) {
        return;
    }

    traversal_inorder_helper(tree->left_child, values);
    values.push_back(tree->value);
    traversal_inorder_helper(tree->right_child, values);
}

vector<int> BinarySearchTree::traversal_inorder_recursive()  {
    vector<int> values;
    traversal_inorder_helper(root, values);
    return values;
}

vector<int> BinarySearchTree::traversal_inorder_iterative() {
    vector<int> values;
    if (root->value == INF) {
        return values; // empty vector
    }

    stack<Node*> traversal;
    Node* current = root;
    bool complete = false;

    while (!complete) {
        if (current != nullptr) {
            traversal.push(current);
            current = current->left_child;
        } else if (!traversal.empty()) {
            current = traversal.top();
            traversal.pop();
            values.push_back(current->value);
            current = current->right_child;
        } else {
            complete = true;
        }
    }
    return values;
}

/*
    Preorder traversal
    ------------------
    This Algorithm visits and displays each node in the following order starting
    with the root node. Parent, followed by the Left subtree, followed by the
    Right subtree.

    Time complexity
    ---------------
    Average case : O(n), where n is the number of nodes in the tree
    Worst case : O(n)

    Space complexity
    ----------------
    O(n), where n is the number if nodes in the tree
*/
void BinarySearchTree::traversal_preorder_helper(Node* tree, vector<int>& values) {
    if (tree == nullptr or tree->value == INF) {
        return;
    }

    values.push_back(tree->value);
    traversal_preorder_helper(tree->left_child, values);
    traversal_preorder_helper(tree->right_child, values);
}

vector<int> BinarySearchTree::traversal_preorder_recursive() {
    vector<int> values;
    traversal_preorder_helper(root, values);
    return values;
}

vector<int> BinarySearchTree::traversal_preorder_iterative() {
    vector<int> values;
    if (root->value == INF) {
        return values; // empty vector
    }

    stack<Node*> traversal;
    Node* current;

    traversal.push(root);

    while (!traversal.empty()) {
        current = traversal.top();
        traversal.pop();
        values.push_back(current->value);

        if (current->right_child != nullptr) {
            traversal.push(current->right_child);
        }

        if (current->left_child != nullptr) {
            traversal.push(current->left_child);
        }
    }
    return values;
}

/*
    Postorder traversal
    -------------------
    This Algorithm visits and displays each node in the following order starting
    with the root node. The Left subtree, followed by the Right subtree,
    followed by the Parent.

    Time complexity
    ---------------
    Average case : O(n), where n is the number of nodes in the tree
    Worst case : O(n)

    Space complexity
    ----------------
    O(n), where n is the number if nodes in the tree
*/
void BinarySearchTree::traversal_postorder_helper(Node* tree, vector<int>& values) {
    if (tree == nullptr or tree->value == INF) {
        return;
    } else {
        traversal_postorder_helper(tree->left_child, values);
        traversal_postorder_helper(tree->right_child, values);
        values.push_back(tree->value);
    }
}

vector<int> BinarySearchTree::traversal_postorder_recursive() {
    vector<int> values;
    traversal_postorder_helper(root, values);
    return values;
}

vector<int> BinarySearchTree::traversal_postorder_iterative() {
    vector<int> values;
    if (root->value == INF) {
        return values; // empty vector
    }

    stack<Node*> traversal;
    Node* current = root;

    do
    {
        while (current)
        {
            if (current->right_child)
                traversal.push(current->right_child);
            traversal.push(current);

            current = current->left_child;
        }

        current = traversal.top();
        traversal.pop();

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (current->right_child and traversal.empty() == false and traversal.top() == current->right_child)
        {
            traversal.pop();
            traversal.push(current);
            current= current->right_child;
        } else {
            values.push_back(current->value);
            current = nullptr;
        }
    } while (!traversal.empty());

    return values;
}

#endif // BINARY_SEARCH_TREE_HPP
