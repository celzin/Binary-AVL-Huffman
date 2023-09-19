#include "include/hash_table.hpp"

std::string remove_em_dash(const std::string &input) {
    std::string result = input;
    size_t pos;
    while ((pos = result.find("—")) != std::string::npos) {
        result.erase(pos, strlen("—"));
    }
    return result;
}

std::string to_lower_accented(const std::string &input) {
    std::string result = input;
    std::map<std::string, std::string> accented = {
        {"Á", "á"}, {"É", "é"}, {"Í", "í"}, {"Ó", "ó"}, {"Ú", "ú"},
        {"À", "à"}, {"È", "è"}, {"Ì", "ì"}, {"Ò", "ò"}, {"Ù", "ù"},
        {"Â", "â"}, {"Ê", "ê"}, {"Î", "î"}, {"Ô", "ô"}, {"Û", "û"},
        {"Ã", "ã"}, {"Õ", "õ"}, {"Ñ", "ñ"}, {"Ç", "ç"}, {"Ü", "ü"}
    };

    for (const auto &pair : accented) {
        size_t pos = result.find(pair.first);
        while (pos != std::string::npos) {
            result.replace(pos, pair.first.length(), pair.second);
            pos = result.find(pair.first, pos + pair.second.length());
        }
    }

    std::transform(result.begin(), result.end(), result.begin(), ::tolower);

    return result;
}

std::string clean_word(const std::string &word) {
    static const std::regex pattern("[^a-zA-ZáéíóúÁÉÍÓÚàèìòùÀÈÌÒÙâêîôûÂÊÎÔÛãõñÑçÇüÜ]");
    std::string cleaned_word = std::regex_replace(word, pattern, "");
    cleaned_word = to_lower_accented(cleaned_word);
    return cleaned_word;
}

HashTable::HashTable(size_t size) : size(size), table(size) {}

void HashTable::insert(const std::string &key) {
    size_t index = hash(key);
    for (auto &entry : table[index]) {
        if (entry.first == key) {
            entry.second++;
            return;
        }
    }
    table[index].push_back(std::make_pair(key, 1));
}

int HashTable::get_frequency(const std::string &key) const {
    size_t index = hash(key);
    for (const auto &entry : table[index]) {
        if (entry.first == key) {
            return entry.second;
        }
    }
    return 0;
}

std::vector<std::pair<std::string, int>> HashTable::get_all_elements() const {
    std::vector<std::pair<std::string, int>> elements;
    for (const auto &bucket : table) {
        for (const auto &entry : bucket) {
            elements.push_back(entry);
        }
    }
    return elements;
}

size_t HashTable::hash(const std::string &key) const {
    size_t hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % size;
    }
    return hash;
}

std::set<std::string> load_stopwords(const std::string &filename) {
    std::set<std::string> stopwords;
    std::ifstream stopwords_file(filename);
    std::string word;
    while (stopwords_file >> word) {
        stopwords.insert(clean_word(word));
    }
    stopwords_file.close();
    return stopwords;
}

void process_file(const std::string &filepath, const std::set<std::string> &stopwords, HashTable &hash_table) {
    std::ifstream input_file(filepath);
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            word = remove_em_dash(word);
            word = clean_word(word);
            if (!word.empty() && stopwords.find(word) == stopwords.end()) {
                hash_table.insert(word);
            }
        }
    }
    input_file.close();
}

std::set<std::string> initialize_stopwords(const std::string &path) {
    return load_stopwords(path);
}

void process_dataset(const std::string &path, const std::set<std::string> &stopwords, HashTable &hash_table) {
    //process_files(path, stopwords, hash_table);
}

int HashTable::get_word_frequency(const std::string &word) const {
    size_t index = hash(word);  // Utiliza a mesma função de hash que o método insert
    for (const auto &entry : table[index]) {
        if (entry.first == word) {
            return entry.second;
        }
    }
    return 0;  // Retorna 0 se a palavra não for encontrada
}