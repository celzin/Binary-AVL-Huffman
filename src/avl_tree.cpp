#include "include/avl_tree.hpp"

AVLNode::AVLNode(std::pair<std::string, int> data) : data(data), height(1), left(nullptr), right(nullptr) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::get_height(AVLNode *node) const {
    return node ? node->height : 0;
}

int AVLTree::get_balance(AVLNode *node) const {
    return node ? get_height(node->left) - get_height(node->right) : 0;
}

// Right Rotation
AVLNode *AVLTree::rotate_right(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + std::max(get_height(y->left), get_height(y->right));
    x->height = 1 + std::max(get_height(x->left), get_height(x->right));

    return x;
}

// Left Rotation
AVLNode *AVLTree::rotate_left(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + std::max(get_height(x->left), get_height(x->right));
    y->height = 1 + std::max(get_height(y->left), get_height(y->right));

    return y;
}

// Insert function
AVLNode *AVLTree::insert(AVLNode *node, const std::pair<std::string, int> &data) {
    // BST insertion
    if (!node)
        return new AVLNode(data);

    if (data.second < node->data.second ||
        (data.second == node->data.second && data.first < node->data.first)) {
        node->left = insert(node->left, data);
    } else if (data.second > node->data.second ||
        (data.second == node->data.second && data.first > node->data.first)) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    // Update height
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    // Get the balance factor
    int balance = get_balance(node);

    // Balance the tree
    // Left heavy
    if (balance > 1 && data.second < node->left->data.second)
        return rotate_right(node);

    // Right heavy
    if (balance < -1 && data.second > node->right->data.second)
        return rotate_left(node);

    // Left-Right heavy
    if (balance > 1 && data.second > node->left->data.second) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Right-Left heavy
    if (balance < -1 && data.second < node->right->data.second) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void AVLTree::insert(const std::pair<std::string, int> &data) {
    root = insert(root, data);
}

// Pre-order traversal function
void AVLTree::pre_order(AVLNode *node, std::vector<std::pair<std::string, int>> &result) const {
    if (node != nullptr) {
        result.push_back(node->data);
        pre_order(node->left, result);
        pre_order(node->right, result);
    }
}

std::vector<std::pair<std::string, int>> AVLTree::pre_order() const {
    std::vector<std::pair<std::string, int>> result;
    pre_order(root, result);
    return result;
}