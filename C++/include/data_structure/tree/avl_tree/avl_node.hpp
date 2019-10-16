#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP
#include <cmath>

struct AVLNode {
    static int get_height(AVLNode*);
    static AVLNode* get_longer_branch(AVLNode*);

    AVLNode(int, AVLNode*, AVLNode*, AVLNode*);
    AVLNode(int);
    AVLNode();

    bool isBalanced() { return std::abs(AVLNode::get_height(leftChild) - AVLNode::get_height(rightChild)) < 2; }
    int child_count() const;
    void recalculate_height();
    
    bool isLeftChild(AVLNode* node) const { return leftChild == node; }
    bool isRightChild(AVLNode* node) const { return rightChild == node; }

    void detach_parent();

    void attach_left_child(AVLNode*);
    void attach_right_child(AVLNode*);

    AVLNode* detach_left_child();
    AVLNode* detach_right_child();

    AVLNode* replace_child(AVLNode*, AVLNode*);

    int value;
    AVLNode* parent;
    AVLNode* leftChild;
    AVLNode* rightChild;
    int height;
};

int AVLNode::get_height(AVLNode* node) {
    if (node == nullptr) return -1;
    else return node->height;
}

AVLNode* AVLNode::get_longer_branch(AVLNode* node) {
    if (node == nullptr) return nullptr;
    int leftBranchHeight = AVLNode::get_height(node->leftChild);
    int rightBranchHeight = AVLNode::get_height(node->rightChild);

    if (leftBranchHeight >= rightBranchHeight)
        return node->leftChild;
    else 
        return node->rightChild;
}

AVLNode::AVLNode(int val, AVLNode* parent, AVLNode* left, AVLNode* right)
    : value(val), parent(parent), leftChild(left), rightChild(right)
{
    recalculate_height();
}

AVLNode::AVLNode(int val)
    : AVLNode(val, nullptr, nullptr, nullptr)
{}

AVLNode::AVLNode()
    : AVLNode(0, nullptr, nullptr, nullptr)
{}

int AVLNode::child_count() const {
    int ret = 0;
    if (leftChild) ++ret;
    if (rightChild) ++ret;
    return ret;
}

void AVLNode::recalculate_height() {
    int leftChildHeight = leftChild ? leftChild->height : -1;
    int rightChildHeight = rightChild ? rightChild->height : -1;

    int newHeight = std::max(leftChildHeight, rightChildHeight) + 1;
    if (newHeight != this->height) {
        this->height = newHeight;
        if (parent != nullptr) {
            parent->recalculate_height();
        }
    }
}

void AVLNode::detach_parent() {
    if (this->parent == nullptr) return;

    if (this->parent->isLeftChild(this)) {
        this->parent->leftChild = nullptr;
    }
    else if (this->parent->isRightChild(this)) {
        this->parent->rightChild = nullptr;
    }
    this->parent->recalculate_height();
    this->parent = nullptr;
}


void AVLNode::attach_left_child(AVLNode* node) {
    this->leftChild = node;
    if (node != nullptr)
        node->parent = this;
    recalculate_height();
}

void AVLNode::attach_right_child(AVLNode* node) {
    this->rightChild = node;
    if (node != nullptr)
        node->parent = this;
    recalculate_height();
}

AVLNode* AVLNode::detach_left_child() {
    AVLNode* toReturn = this->leftChild; 
    if (this->leftChild != nullptr)
        this->leftChild->parent = nullptr;    
    this->leftChild = nullptr;
    recalculate_height();
    return toReturn;
}

AVLNode* AVLNode::detach_right_child() {
    AVLNode* toReturn = this->rightChild; 
    if (this->rightChild != nullptr)
        this->rightChild->parent = nullptr;    
    this->rightChild = nullptr;
    recalculate_height();
    return toReturn;
}

AVLNode* AVLNode::replace_child(AVLNode* oldChild, AVLNode* newChild) {
    if (isLeftChild(oldChild)) {
        detach_left_child();
        attach_left_child(newChild);
        return oldChild;
    }
    else if (isRightChild(oldChild)) {
        detach_right_child();
        attach_right_child(newChild);
        return oldChild;
    }
    throw std::runtime_error("oldChild is not a child of node");
    return nullptr;
}
#endif // AVL_NODE_HPP