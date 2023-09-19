#include "include/binary_tree.hpp"

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(const std::pair<std::string, int> &data) {
    insert(root, data);
}

void BinaryTree::insert(Node *&node, const std::pair<std::string, int> &data) {
    if (node == nullptr) {
        node = new Node(data);
    } else {
        if (data.second < node->data.second ||
            (data.second == node->data.second && data.first < node->data.first)) {
            insert(node->left, data);
        } else {
            insert(node->right, data);
        }
    }
}

// std::vector<std::string> BinaryTree::pre_order() const {
//     std::vector<std::string> result;
//     pre_order(root, result);
//     return result;
// }

// void BinaryTree::pre_order(Node *node, std::vector<std::string> &result) const {
//     if (node != nullptr) {
//         result.push_back(node->data.first);
//         pre_order(node->left, result);
//         pre_order(node->right, result);
//     }
// }

std::vector<std::pair<std::string, int>> BinaryTree::pre_order() const {
    std::vector<std::pair<std::string, int>> result;
    pre_order(root, result);
    return result;
}

void BinaryTree::pre_order(Node *node, std::vector<std::pair<std::string, int>> &result) const {
    if (node != nullptr) {
        result.push_back(node->data);
        pre_order(node->left, result);
        pre_order(node->right, result);
    }
}

// Método para travessia em ordem
std::vector<std::string> BinaryTree::in_order() const {
    std::vector<std::string> result;
    in_order(root, result);
    return result;
}

void BinaryTree::in_order(Node *node, std::vector<std::string> &result) const {
    if (node == nullptr) return;

    in_order(node->left, result);
    result.push_back(node->data.first);
    in_order(node->right, result);
}

// Método para travessia em pós-ordem
std::vector<std::string> BinaryTree::post_order() const {
    std::vector<std::string> result;
    post_order(root, result);
    return result;
}

void BinaryTree::post_order(Node *node, std::vector<std::string> &result) const {
    if (node == nullptr) return;

    post_order(node->left, result);
    post_order(node->right, result);
    result.push_back(node->data.first);
}


