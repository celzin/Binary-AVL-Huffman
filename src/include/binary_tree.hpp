#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <vector>
#include <string>
#include <utility>

struct Node {
    std::pair<std::string, int> data;
    Node *left;
    Node *right;
    Node(std::pair<std::string, int> data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree();
    void insert(const std::pair<std::string, int> &data);
    std::vector<std::pair<std::string, int>> pre_order() const;
    std::vector<std::string> in_order() const;
    std::vector<std::string> post_order() const;

private:
    Node *root;
    void insert(Node *&node, const std::pair<std::string, int> &data);
    void pre_order(Node *node, std::vector<std::pair<std::string, int>> &result) const;
    void in_order(Node *node, std::vector<std::string> &result) const;
    void post_order(Node *node, std::vector<std::string> &result) const;

};

#endif // BINARY_TREE_HPP