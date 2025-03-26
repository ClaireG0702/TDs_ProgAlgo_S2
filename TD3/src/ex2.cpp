#include <vector>
#include <iostream>

void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right) {
    size_t left_vec_size = middle - left + 1;
    size_t right_vec_size = right - middle;

    std::vector<int> left_vec(left_vec_size);
    std::vector<int> right_vec(right_vec_size);

    for (size_t i = 0; i < left_vec_size; ++i)
        left_vec[i] = vec[left + i];
    for (size_t j = 0; j < right_vec_size; ++j)
        right_vec[j] = vec[middle + 1 + j];

    size_t i = 0, j = 0, k = left;
    while (i < left_vec_size && j < right_vec_size) {
        if (left_vec[i] <= right_vec[j]) {
            vec[k] = left_vec[i];
            ++i;
        } else {
            vec[k] = right_vec[j];
            ++j;
        }
        ++k;
    }

    while (i < left_vec_size) {
        vec[k] = left_vec[i];
        ++i;
        ++k;
    }

    while (j < right_vec_size) {
        vec[k] = right_vec[j];
        ++j;
        ++k;
    }
}

void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;

        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);

        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

int main() {
    std::vector<int> vec = { 12, 4, 6, 1, 3, 5, 7, 9, 8 };
    
    std::cout << "Before sorting: " << std::endl;
    for (auto const & elem : vec)
        std::cout << elem << ' ';
    std::cout << "\n\n";
    
    merge_sort(vec);
    std::cout << "After sorting: " << std::endl;
    for (auto const & elem : vec)
        std::cout << elem << ' ';
    std::cout << "\n\n";

    return 0;
}