#include "include/heap.hpp"

Heap::Heap(int k) : k(k) {}

void Heap::insert(const std::pair<std::string, int> &element) {
    elements.push_back(element);
    heapify_up();
    if (elements.size() > k) {
        elements[0] = elements.back();
        elements.pop_back();
        heapify_down(0);
    }
}

std::vector<std::pair<std::string, int>> Heap::get_top_k() const {
    return elements;
}

void Heap::heapify_up() {
    int index = elements.size() - 1;
    while (index > 0 && elements[index].second < elements[parent_index(index)].second) {
        std::swap(elements[index], elements[parent_index(index)]);
        index = parent_index(index);
    }
}

void Heap::heapify_down(int index) {
    int smallest = index;
    if (left_child_index(index) < elements.size() && elements[left_child_index(index)].second < elements[smallest].second) {
        smallest = left_child_index(index);
    }
    if (right_child_index(index) < elements.size() && elements[right_child_index(index)].second < elements[smallest].second) {
        smallest = right_child_index(index);
    }
    if (smallest != index) {
        std::swap(elements[index], elements[smallest]);
        heapify_down(smallest);
    }
}

int Heap::left_child_index(int index) const {
    return 2 * index + 1;
}

int Heap::right_child_index(int index) const {
    return 2 * index + 2;
}

int Heap::parent_index(int index) const {
    return (index - 1) / 2;
}

// void fill_heap_with_top_elements(Heap &heap, const HashTable &hash_table) {
//     auto all_elements = hash_table.get_all_elements(); // Supondo que você tem um método que retorna todos os elementos
//     std::sort(all_elements.begin(), all_elements.end(),
//         [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
//         return a.second > b.second;
//     });

//     for (size_t i = 0; i < std::min(all_elements.size(), static_cast<size_t>(TOP_K + 1)); ++i) {
//         heap.insert(all_elements[i]);
//     }
// }

// std::pair<std::string, int> Heap::get_next_top() {
//     if (elements.size() == 0) {
//         return { "", -1 };
//     }

//     return elements[0];  // O elemento na raiz da min-heap é o menor elemento.
// }

// Esta função será responsável por preencher o heap com 'top-k + 1' palavras
void fill_heap_with_top_elements(Heap &heap, const HashTable &hash_table) {
    auto all_elements = hash_table.get_all_elements();
    std::sort(all_elements.begin(), all_elements.end(),
        [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
        return a.second > b.second;
    });

    // Pegue 'top-k + 1' elementos
    for (size_t i = 0; i < std::min(all_elements.size(), static_cast<size_t>(TOP_K + 1)); ++i) {
        heap.insert(all_elements[i]);
    }
}

// Esta função será responsável por pegar as 'top-k' palavras e lidar com a 'palavra-pesquisada'
std::vector<std::pair<std::string, int>> get_top_k_words_with_removal(Heap &heap, const std::string &searched_word) {
    auto top_k_plus_one = heap.get_top_k();

    auto it = std::find_if(top_k_plus_one.begin(), top_k_plus_one.end(),
        [&searched_word](const std::pair<std::string, int> &pair) {
        return pair.first == searched_word;
    });

    // Se encontrarmos a 'palavra-pesquisada', a removemos.
    if (it != top_k_plus_one.end()) {
        top_k_plus_one.erase(it);
    } else {
        // Caso contrário, remova o último elemento, que é a 'top-k + 1' palavra.
        top_k_plus_one.pop_back();
    }

    return top_k_plus_one;
}