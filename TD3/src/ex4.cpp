#include <vector>
#include <iostream>

int search(const std::vector<int>& vec, int value) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] == value) {
            return mid;
        } else if (vec[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> sorted_vec = {1, 2, 2, 3, 4, 8, 12};
    int value = 8;

    int index = search(sorted_vec, value);
    if (index != -1) {
        std::cout << "Value " << value << " found at index " << index << std::endl;
    } else {
        std::cout << "Value " << value << " not found in the array" << std::endl;
    }

    return 0;
}