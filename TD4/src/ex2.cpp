#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

auto const is_space = [](char letter){ 
    return letter == ' '; 
};

int count_letters_in_first_word(std::string const& str) {
    auto it = std::find_if(str.begin(), str.end(), is_space);

    return std::distance(str.begin(), it);
}

std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> words;
    auto it = str.begin();

    while(it != str.end()) {
        auto it_space = std::find_if(it, str.end(), is_space);
        words.push_back(std::string(it, it_space));
        it = it_space;
        if(it != str.end()) {
            it = std::find_if_not(it, str.end(), is_space);
        }
    }

    return words;
}

int main() {
    std::string str = "This is a test string";
    std::cout << "Number of letters in the first word: " << count_letters_in_first_word(str) << std::endl;

    std::vector<std::string> words = split_string(str);
    for(auto const& word : words) {
        std::cout << word << " | ";
    }
    std::cout << std::endl;

    return 0;
}