cmake_minimum_required(VERSION 3.12)

project("Autocomplete" VERSION 1.0.0)

add_executable(app "src/main.cpp" "src/hash_table.cpp" "src/heap.cpp" "src/avl_tree.cpp" "src/binary_tree.cpp" "src/huffman_node.cpp" "src/dataset_processing.cpp")