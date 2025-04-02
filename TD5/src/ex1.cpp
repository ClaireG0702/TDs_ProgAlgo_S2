#include <string>
#include <iostream>
#include <math.h>

size_t folding_string_hash_sum(std::string const& s, size_t max) {
    size_t hash {0};
    for (char c : s) {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {0};
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1);
        hash %= max;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash {0};
    int power {1};
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * power;
        hash %= m;
        power = (power * p) % m;
    }
    return hash;
}

int main() {
    std::string s1 = "hello";
    std::string s2 = "world";

    size_t max = 1024;
    size_t hash1 = folding_string_hash_sum(s1, max);
    size_t hash2 = folding_string_hash_sum(s2, max);
    std::cout << "Hash of \"" << s1 << "\": " << hash1 << std::endl;
    std::cout << "Hash of \"" << s2 << "\": " << hash2 << std::endl;

    hash1 = folding_string_ordered_hash(s1, max);
    hash2 = folding_string_ordered_hash(s2, max);
    std::cout << "Ordered hash of \"" << s1 << "\": " << hash1 << std::endl;
    std::cout << "Ordered hash of \"" << s2 << "\": " << hash2 << std::endl;

    int p = 31;
    size_t m = 1e9 + 9;
    hash1 = polynomial_rolling_hash(s1, p, m);
    hash2 = polynomial_rolling_hash(s2, p, m);
    std::cout << "Polynomial rolling hash of \"" << s1 << "\": " << hash1 << std::endl;
    std::cout << "Polynomial rolling hash of \"" << s2 << "\": " << hash2 << std::endl;

    return 0;
}