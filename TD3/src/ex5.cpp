#include <vector>
#include <iostream>

void counting_sort(std::vector<int> & vec, int const max) {
    std::vector<int> count(max+1, 0);
    std::vector<int> output(vec.size());

    for(auto const& elem : vec) {
        count[elem]++;
    }

    for(int i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }

    for(int i = vec.size()-1; i >= 0; i--) {
        output[count[vec[i]]-1] = vec[i];
        count[vec[i]]--;
    }

    for(int i = 0; i < vec.size(); i++) {
        vec[i] = output[i];
    }
}

int main() {
    std::vector<int> vec = {4, 2, 2, 8, 3, 3, 1};
    int max_value = 8;

    std::cout << "Original vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    counting_sort(vec, max_value);

    std::cout << "Sorted vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}