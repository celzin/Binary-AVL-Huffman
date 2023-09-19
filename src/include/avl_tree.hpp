#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <vector>
#include <utility>
#include <string>

class AVLNode {
public:
    std::pair<std::string, int> data;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode(std::pair<std::string, int> data);
};

class AVLTree {
public:
    AVLTree();
    void insert(const std::pair<std::string, int> &data);
    std::vector<std::pair<std::string, int>> pre_order() const;
    std::vector<std::pair<std::string, int>> in_order() const;
    std::vector<std::pair<std::string, int>> post_order() const;

private:
    AVLNode *root;
    AVLNode *insert(AVLNode *node, const std::pair<std::string, int> &data);
    int get_height(AVLNode *node) const;
    int get_balance(AVLNode *node) const;
    AVLNode *rotate_right(AVLNode *y);
    AVLNode *rotate_left(AVLNode *x);
    void pre_order(AVLNode *node, std::vector<std::pair<std::string, int>> &result) const;
    void in_order(AVLNode *node, std::vector<std::pair<std::string, int>> &result) const;
    void post_order(AVLNode *node, std::vector<std::pair<std::string, int>> &result) const;
};

#endif // AVL_TREE_HPP