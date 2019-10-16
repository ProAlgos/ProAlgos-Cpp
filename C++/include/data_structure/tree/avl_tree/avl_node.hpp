#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP
#include <cmath>

struct AVLNode {
    static int get_height(AVLNode*);
    static AVLNode* get_longer_branch(AVLNode*);

    AVLNode(int, AVLNode*, AVLNode*, AVLNode*);
    AVLNode(int);
    AVLNode();

    bool is_balanced() const;
    int child_count() const;
    void adjust_height();
    
    bool is_left_child(AVLNode* node) const { return left_child == node; }
    bool is_right_child(AVLNode* node) const { return right_child == node; }

    void detach_parent();

    void attach_left_child(AVLNode*);
    void attach_right_child(AVLNode*);

    AVLNode* detach_left_child();
    AVLNode* detach_right_child();

    AVLNode* replace_child(AVLNode*, AVLNode*);

    int value;
    AVLNode* parent;
    AVLNode* left_child;
    AVLNode* right_child;
    int height;
};

int AVLNode::get_height(AVLNode* node) {
    if (node == nullptr) return -1;
    else return node->height;
}

AVLNode* AVLNode::get_longer_branch(AVLNode* node) {
    if (node == nullptr) return nullptr;
    int leftBranchHeight = AVLNode::get_height(node->left_child);
    int rightBranchHeight = AVLNode::get_height(node->right_child);

    if (leftBranchHeight >= rightBranchHeight)
        return node->left_child;
    else 
        return node->right_child;
}

AVLNode::AVLNode(int val, AVLNode* parent, AVLNode* left, AVLNode* right)
    : value(val), parent(parent), left_child(left), right_child(right)
{
    adjust_height();
}

AVLNode::AVLNode(int val)
    : AVLNode(val, nullptr, nullptr, nullptr)
{}

AVLNode::AVLNode()
    : AVLNode(0, nullptr, nullptr, nullptr)
{}

bool AVLNode::is_balanced() const { 
    return std::abs(get_height(left_child) - get_height(right_child)) < 2;
}

int AVLNode::child_count() const {
    int ret = 0;
    if (left_child) ++ret;
    if (right_child) ++ret;
    return ret;
}

void AVLNode::adjust_height() {
    int leftChildHeight = left_child ? left_child->height : -1;
    int rightChildHeight = right_child ? right_child->height : -1;

    int newHeight = std::max(leftChildHeight, rightChildHeight) + 1;
    if (newHeight != this->height) {
        this->height = newHeight;
        if (parent != nullptr) {
            parent->adjust_height();
        }
    }
}

void AVLNode::detach_parent() {
    if (this->parent == nullptr) return;

    if (this->parent->is_left_child(this)) {
        this->parent->left_child = nullptr;
    }
    else if (this->parent->is_right_child(this)) {
        this->parent->right_child = nullptr;
    }
    this->parent->adjust_height();
    this->parent = nullptr;
}


void AVLNode::attach_left_child(AVLNode* node) {
    this->left_child = node;
    if (node != nullptr)
        node->parent = this;
    adjust_height();
}

void AVLNode::attach_right_child(AVLNode* node) {
    this->right_child = node;
    if (node != nullptr)
        node->parent = this;
    adjust_height();
}

AVLNode* AVLNode::detach_left_child() {
    AVLNode* toReturn = this->left_child; 
    if (this->left_child != nullptr)
        this->left_child->parent = nullptr;    
    this->left_child = nullptr;
    adjust_height();
    return toReturn;
}

AVLNode* AVLNode::detach_right_child() {
    AVLNode* toReturn = this->right_child; 
    if (this->right_child != nullptr)
        this->right_child->parent = nullptr;    
    this->right_child = nullptr;
    adjust_height();
    return toReturn;
}

AVLNode* AVLNode::replace_child(AVLNode* oldChild, AVLNode* newChild) {
    if (is_left_child(oldChild)) {
        detach_left_child();
        attach_left_child(newChild);
        return oldChild;
    }
    else if (is_right_child(oldChild)) {
        detach_right_child();
        attach_right_child(newChild);
        return oldChild;
    }
    else {
        throw std::runtime_error("oldChild is not a child of node");
        return nullptr;
    }
}
#endif // AVL_NODE_HPP