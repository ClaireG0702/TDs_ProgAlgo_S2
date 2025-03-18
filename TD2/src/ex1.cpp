#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <cctype>
#include <stack>
#include <cmath>

std::vector<std::string> split_string(std::string const& s)
{
    std::cout << "Splitting string: " << s << std::endl;
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s) {
    for(std::string::size_type i = 0; i < s.size(); i++) {
        if(!std::isdigit(s[i]) && s[i] != '.') {
            return false;
        }
    }

    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> stack;

    for(std::vector<std::string>::size_type i = 0; i < tokens.size(); i++) {
        if(is_floating(tokens[i])) {
            stack.push(std::stof(tokens[i]));
        } else if (stack.size() <= 2) {
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();

            if(tokens[i] == "+") {
                stack.push(leftOperand + rightOperand);
            } else if(tokens[i] == "-") {
                stack.push(leftOperand - rightOperand);
            } else if(tokens[i] == "*") {
                stack.push(leftOperand * rightOperand);
            } else if(tokens[i] == "/") {
                stack.push(leftOperand / rightOperand);
            } else if(tokens[i] == "^") {
                stack.push(std::pow(leftOperand, rightOperand));
            } else {
                std::cout << "Invalid operator" << std::endl;
                return -1;
            }
        } else {
            std::cout << "Invalid expression" << std::endl;
            return -1;
        }
    }

    if (stack.size() != 1) {
        std::cout << "Invalid expression" << std::endl;
        return -1;
    }

    return stack.top();
}

int main() {
    std::string npi;
    std::vector<std::string> npi_parts;

    std::cout << "Enter your NPI: ";
    std::getline(std::cin, npi);

    npi_parts = split_string(npi);

    std::cout << "Result: " << npi_evaluate(npi_parts) << std::endl;

    return 0;
}