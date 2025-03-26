#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

void fill_random_vector(std::vector<int>& vec, int max_value = 100) {
    std::srand(std::time(nullptr));
    std::generate(vec.begin(), vec.end(), [max_value]() { 
        return std::rand() % (max_value + 1); 
    });
}

void print_vector(const std::vector<int>& vec) {
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void search_in_vector(const std::vector<int>& vec, int num) {
    auto it = std::find(vec.begin(), vec.end(), num);

    if(it != vec.end()) {
        std::cout << "Found " << num << " at position " << it - vec.begin() << std::endl;
    } else {
        std::cout << "Could not find " << num << std::endl;
    }
}

int count_occurrences(const std::vector<int>& vec, int num) {
    return std::count(vec.begin(), vec.end(), num);
}

void sort_vector(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

void accumulate_vector(const std::vector<int>& vec) {
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of all elements: " << sum << std::endl;
}

int main() {
    std::vector<int> vec(10);
    fill_random_vector(vec);

    print_vector(vec);

    int num;
    std::cout << "Enter a number to search: ";
    std::cin >> num;
    search_in_vector(vec, num);

    std::cout << "Enter a number to count: ";
    std::cin >> num;
    std::cout << "Number of occurrences: " << count_occurrences(vec, num) << std::endl;

    sort_vector(vec);
    print_vector(vec);

    accumulate_vector(vec);

    return 0;
}