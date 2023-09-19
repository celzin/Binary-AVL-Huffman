#include "include/dataset_processing.hpp"
#include <fstream>

std::vector<std::string> load_search_terms(const std::string &filename) {
    std::vector<std::string> search_terms;
    std::ifstream input_file(filename);
    std::string line;
    while (std::getline(input_file, line)) {
        search_terms.push_back(line);  // assumindo que as palavras já estão limpas
    }
    input_file.close();
    return search_terms;
}

void process_dataset_files(const std::string &dataset_path, const std::string &stopwords_path, std::ofstream &output_file, const std::vector<std::string> &search_words) {
    auto stopwords = initialize_stopwords(stopwords_path);
    DIR *dir;
    struct dirent *ent;

    output_file << "| Palavra Pesquisada | Frequência | Texto-Origem |-------------------- Top-k-Palavras ------------------|\n"; // Cabeçalho da tabela

    if ((dir = opendir(dataset_path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string filename(ent->d_name);
            if (filename != "." && filename != ".." && filename != "stopwords.txt" && filename != "output.data" && filename != "input.data") {
                HashTable hash_table(TABLE_SIZE);
                Heap heap(TOP_K + 1);

                BinaryTree binaryTree;
                AVLTree avlTree;

                std::string full_file_path = dataset_path + "/" + filename;
                process_file(full_file_path, stopwords, hash_table);

                fill_heap_with_top_elements(heap, hash_table);

                // Tratamento para retirar a "palavra pesquisada" das "top-k palavras", se necessário
                std::vector<std::pair<std::string, int>> top_k = heap.get_top_k();

                for (const auto &search_term : search_words) {
                    auto it = std::find_if(top_k.begin(), top_k.end(),
                        [&search_term](const std::pair<std::string, int> &element) {
                        return element.first == search_term;
                    });

                    if (it != top_k.end()) {
                        top_k.erase(it);
                    }
                }

                if (top_k.size() > TOP_K) {  // Se ainda tivermos TOP_K + 1 palavras após remover a palavra pesquisada, removemos a última
                    top_k.pop_back();
                }

                // Iniciar a medição de tempo para a árvore binária
                auto start_binary = std::chrono::high_resolution_clock::now();
                // Inserir os elementos na árvore binária
                for (const auto &element : top_k) {
                    binaryTree.insert(element);
                }

                // Iniciar a medição de tempo para a árvore AVL
                auto start_avl = std::chrono::high_resolution_clock::now();
                for (const auto &element : top_k) {
                    avlTree.insert(element);
                }

                // E, finalmente, para Huffman
                auto start_huffman = std::chrono::high_resolution_clock::now();
                // Construa a árvore de Huffman
                HuffmanNode *huffmanRoot = build_huffman_tree(top_k);
                // Gere os códigos de Huffman
                std::unordered_map<std::string, std::string> huffmanCodes;
                generate_huffman_codes(huffmanRoot, "", huffmanCodes);

                for (const auto &search_word : search_words) {
                    // int freq = hash_table.get_word_frequency(search_word); // get_word_frequency
                    auto freq = hash_table.get_word_frequency(search_word);
                    if (freq > 0) {
                        output_file << std::endl << search_word << std::setw(25) << freq << std::setw(20) << filename << std::setw(10);

                        // Imprima as top k palavras
                        output_file << "{";
                        for (size_t i = 0; i < top_k.size(); ++i) {
                            output_file << top_k[i].first << "(" << top_k[i].second << ")";  // Imprime a palavra e não a frequência
                            if (i < top_k.size() - 1) {
                                output_file << ", ";
                            }
                        }
                        output_file << "}\n" << std::endl;

                        // Imprimir pré-ordem da árvore binária
                        output_file << std::setw(50) << "" << "|------------------ Pré-Ordem-Binária -----------------|" << std::endl;
                        auto pre_order_words = binaryTree.pre_order();
                        output_file << std::setw(55) << "{";
                        for (size_t i = 0; i < pre_order_words.size(); ++i) {
                            output_file << pre_order_words[i].first << " (" << pre_order_words[i].second << ")";
                            if (i < pre_order_words.size() - 1) {
                                output_file << ", ";
                            }
                        }
                        output_file << "}\n";

                        // Finalizar tempo Binaria
                        auto end_binary = std::chrono::high_resolution_clock::now();
                        auto binary_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_binary - start_binary).count();
                        output_file << std::setw(60) << "" << "( Tempo Binária: " << binary_duration << " microssegundos )\n" << std::endl;

                        // Imprimir pré-ordem da árvore AVL                     
                        output_file << std::setw(50) << "" << "|------------------- Pré-Ordem-AVL --------------------|" << std::endl;
                        auto pre_order_avl = avlTree.pre_order();
                        output_file << std::setw(55) << "{";
                        for (const auto &word : pre_order_avl) {
                            output_file << word.first << " (" << word.second << "), ";
                        }
                        output_file << "}\n";

                        // Finalizar tempo AVL
                        auto end_avl = std::chrono::high_resolution_clock::now();
                        auto avl_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_avl - start_avl).count();
                        output_file << std::setw(60) << "" << "( Tempo AVL: " << avl_duration << " microssegundos )\n" << std::endl;

                        // Imprimir Huffman
                        std::vector<std::pair<std::string, std::string>> pre_order_huffman_list;
                        pre_order_huffman(huffmanRoot, huffmanCodes, pre_order_huffman_list);
                        output_file << std::setw(50) << "" << "|----------------- Códigos de Huffman -----------------|" << std::endl;
                        for (const auto &entry : pre_order_huffman_list) {
                            output_file << std::setw(60) << "" << "| " << entry.first << " -> " << entry.second << std::endl;
                        }

                        // Finalizar tempo Huffman
                        auto end_huffman = std::chrono::high_resolution_clock::now();
                        auto huffman_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_huffman - start_huffman).count();
                        output_file << std::setw(60) << "" << "( Tempo Huffman: " << huffman_duration << " microssegundos )\n";

                        output_file << "--------------------------------------------------------------------------------------------------" << std::endl;
                    }
                }
            }
        }
        closedir(dir);
    }
}

