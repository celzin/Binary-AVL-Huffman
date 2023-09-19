#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <iostream>    
#include <vector>
#include <list>
#include <set>
#include <string>
#include <fstream> 
#include <sstream>  
#include <regex>
#include <algorithm>
#include <dirent.h>
#include <cctype>

class HashTable {
public:
    HashTable(size_t size); //
    void insert(const std::string &key); //
    int get_frequency(const std::string &key) const; //
    std::string remove_em_dash(const std::string &input); // 
    std::string to_lower_accented(const std::string &input); //
    std::string clean_word(const std::string &word); //
    std::vector<std::pair<std::string, int>> get_all_elements() const; //
    int get_word_frequency(const std::string &word) const; // new

private:
    // int hash_function(const std::string &word) const; // new
    size_t hash(const std::string &key) const; //
    size_t size;
    std::vector<std::list<std::pair<std::string, int>>> table;
};

void process_file(const std::string &filepath, const std::set<std::string> &stopwords, HashTable &hash_table); //
void process_dataset(const std::string &path, const std::set<std::string> &stopwords, HashTable &hash_table); //
std::set<std::string> load_stopwords(const std::string &filename); //
std::set<std::string> initialize_stopwords(const std::string &path); //

#endif  // HASH_TABLE_HPP