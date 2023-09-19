#include "include/huffman_node.hpp"
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>

HuffmanNode::HuffmanNode(const std::string &word, int frequency)
    : word(word), frequency(frequency), left(nullptr), right(nullptr) {}

HuffmanNode::~HuffmanNode() {
    delete left;
    delete right;
}

// Função para comparar a frequência dos nós no min-heap
struct Compare {
    bool operator()(HuffmanNode *l, HuffmanNode *r) {
        return (l->frequency > r->frequency);
    }
};

// Função para construir a árvore Huffman
HuffmanNode *build_huffman_tree(const std::vector<std::pair<std::string, int>> &top_k) {
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> min_heap;

    // Construa o min heap
    for (const auto &element : top_k) {
        min_heap.push(new HuffmanNode(element.first, element.second));
    }

    while (min_heap.size() > 1) {
        HuffmanNode *left = min_heap.top();
        min_heap.pop();

        HuffmanNode *right = min_heap.top();
        min_heap.pop();

        // Verifique se as frequências são as mesmas e ajuste com base na ordem alfabética
        if (left->frequency == right->frequency && left->word > right->word) {
            std::swap(left, right);
        }

        HuffmanNode *merged = new HuffmanNode("", left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        min_heap.push(merged);
    }

    return min_heap.top();
}

// Função para gerar os códigos Huffman a partir da árvore
void generate_huffman_codes(HuffmanNode *root, const std::string &code, std::unordered_map<std::string, std::string> &huffmanCodes) {
    if (!root) {
        return;
    }

    if (root->word != "") {
        huffmanCodes[root->word] = code;
    }

    generate_huffman_codes(root->left, code + "0", huffmanCodes);
    generate_huffman_codes(root->right, code + "1", huffmanCodes);
}

void pre_order_huffman(HuffmanNode *root, const std::unordered_map<std::string, std::string> &huffmanCodes, std::vector<std::pair<std::string, std::string>> &pre_order_list) {
    if (root) {
        if (!root->word.empty()) {
            pre_order_list.push_back({ root->word, huffmanCodes.at(root->word) });
        }
        pre_order_huffman(root->left, huffmanCodes, pre_order_list);
        pre_order_huffman(root->right, huffmanCodes, pre_order_list);
    }
}
