#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

#include <string>
#include <vector>
#include <unordered_map>

class HuffmanNode {
public:
    std::string word;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(const std::string &word, int frequency);
    ~HuffmanNode();
};

// Protótipos das funções
HuffmanNode *build_huffman_tree(const std::vector<std::pair<std::string, int>> &top_k);
void generate_huffman_codes(HuffmanNode *root, const std::string &code, std::unordered_map<std::string, std::string> &huffmanCodes);
void pre_order_huffman(HuffmanNode *root, const std::unordered_map<std::string, std::string> &huffmanCodes, std::vector<std::pair<std::string, std::string>> &pre_order_list);

#endif // HUFFMAN_NODE_H