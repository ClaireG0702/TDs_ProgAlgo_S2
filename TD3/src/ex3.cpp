#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { 
        return std::rand() % max;
    });
    
    return vec;
}

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

void measure_std_sort(std::vector<int> vec) {
    ScopedTimer timer("std::sort");
    std::sort(vec.begin(), vec.end());
}

void measure_bubble_sort(std::vector<int> vec) {
    ScopedTimer timer("Bubble sort");
    for(size_t i = 0; i < vec.size(); i++) {
        for(size_t j = 0; j < vec.size() - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void measure_selection_sort(std::vector<int> vec) {
    ScopedTimer timer("Selection sort");
    for(size_t i = 0; i < vec.size(); i++) {
        size_t min = i;
        for(size_t j = i + 1; j < vec.size(); j++) {
            if(vec[j] < vec[min]) {
                min = j;
            }
        }
        if(min != i) {
            std::swap(vec[i], vec[min]);
        }
    }
}

void measured_merge_sort(std::vector<int> vec) {
    ScopedTimer timer("Merge sort");
    merge_sort(vec);
}

int main() {
    std::vector<int> vec = generate_random_vector(100);

    measure_std_sort(vec);

    vec = generate_random_vector(100);
    measure_bubble_sort(vec);

    vec = generate_random_vector(100);
    measure_selection_sort(vec);    

    vec = generate_random_vector(100);
    measured_merge_sort(vec);

    return 0;
}