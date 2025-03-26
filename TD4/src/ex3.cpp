#include <iostream>
#include <string>

bool is_a_palindrome(std::string const& str ) {
    auto it1 = str.begin();
    auto it2 = str.end() - 1;

    while (it1 < it2) {
        if (*it1 != *it2) {
            return false;
        }
        ++it1;
        --it2;
    }

    return true;
}

int main() {
    std::string str = "kayak";
    std:: cout << "Is 'kayak' a palindrome :" << std::endl;
    std::cout << is_a_palindrome(str) << std::endl;

    std::string str2 = "hello";
    std:: cout << "Is 'hello' a palindrome :" << std::endl;
    std::cout << is_a_palindrome(str2) << std::endl;

    return 0;
}