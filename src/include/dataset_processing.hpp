// Arquivo "dataset_processing.hpp":

#ifndef DATASET_PROCESSING_HPP
#define DATASET_PROCESSING_HPP

#include "hash_table.hpp"
#include "heap.hpp"
#include "constants.hpp"
#include "binary_tree.hpp"
#include "avl_tree.hpp"
#include "huffman_node.hpp"
#include <string>
#include <set>
#include <iomanip>
#include <iostream>
#include <chrono>

void process_dataset_files(const std::string &dataset_path, const std::string &stopwords_path, std::ofstream &output_file, const std::vector<std::string> &search_words);
std::vector<std::string> load_search_terms(const std::string &filename);

#endif