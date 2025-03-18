#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <cctype>
#include <stack>
#include <cmath>
#include "tokens.hpp"

int main() {
    std::string npi;
    std::vector<Token> npi_parts;

    std::cout << "Enter your NPI: ";
    std::getline(std::cin, npi);

    npi_parts = tokenize(npi);

    std::cout << "Result: " << npi_evaluate(npi_parts) << std::endl;

    return 0;
}