#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

void bubble_sort(std::vector<int> & vec) {
    int iterations = 0;

    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size() - i - 1; j++) {
            if(vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);

                std::cout << "Iteration " << iterations++ << ": ";
                for(auto const& elem : vec) {
                    std::cout << elem << " ";
                }
                std::cout << std::endl;
            }
        }

        if(is_sorted(vec)) {
            break;
        }
    }
}

void selection_sort(std::vector<int> & vec) {
    int iterations = 0;

    for(int i = 0; i < vec.size(); i++) {
        int min = i;

        for(int j = i+1; j < vec.size(); j++) {
            if(vec[j] < vec[min]) {
                min = j;
            }
        }
        if(min != i) {
            std::swap(vec[i], vec[min]);
    
            std::cout << "Iteration " << iterations++ << ": ";
            for(auto const& elem : vec) {
                std::cout << elem << " ";   
            }
            std::cout << std::endl;
        }

        if(is_sorted(vec)) {
            break;
        }
    }
}

int main() {
    std::vector<int> vec = {5, 2, 3, 1, 4};

    std::cout << "Default table: " << std::endl;
    for(auto const& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "\n\n";

    std::cout << "Bubble sort: " << std::endl;
    bubble_sort(vec);
    std::cout << "\n\n";

    vec = {5, 2, 3, 1, 4};
    std::cout << "Selection sort: " << std::endl;
    selection_sort(vec);
    std::cout << "\n\n";

    return 0;
}