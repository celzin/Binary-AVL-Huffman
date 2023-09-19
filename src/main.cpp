#include <iostream>
#include <fstream>
#include "include/hash_table.hpp"
#include "include/heap.hpp"
#include "include/dataset_processing.hpp"
#include "include/constants.hpp"

int main() {
    std::vector<std::string> search_terms = load_search_terms("dataset/input.data");
    std::ofstream output_file("dataset/output.data");
    process_dataset_files(DATASET_PATH, STOPWORDS_PATH, output_file, search_terms);
    output_file.close();
    return 0;
}