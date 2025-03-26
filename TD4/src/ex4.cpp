#include <iostream>
#include <vector>
#include <numeric>

int sum_of_square(std::vector<int> vec) {
    return std::accumulate(vec.begin(), vec.end(), 0, [](int sum, int val) {
        return sum + val * val;
    });
}

int multiply_even_numbers(std::vector<int> vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, [](int product, int val) {
        return (val % 2 == 0) ? product * val : product;
    });
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector: ";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Sum of squares: " << sum_of_square(vec) << std::endl;
    std::cout << "Product of even numbers: " << multiply_even_numbers(vec) << std::endl;

    return 0;
}