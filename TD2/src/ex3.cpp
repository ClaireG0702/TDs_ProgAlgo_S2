#include "tokens.hpp"

void print_npi_expression(const std::vector<Token>& npi_tokens) {
    for (const auto& token : npi_tokens) {
        if (token.type == TokenType::OPERAND) {
            std::cout << token.value << " ";
        } else {
            switch (token.op) {
                case Operator::ADD: std::cout << "+ "; break;
                case Operator::SUB: std::cout << "- "; break;
                case Operator::MUL: std::cout << "* "; break;
                case Operator::DIV: std::cout << "/ "; break;
                case Operator::POW: std::cout << "^ "; break;
                default: break;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string npi;
    std::vector<Token> npi_parts;

    std::cout << "Enter your infix expression : ";
    std::getline(std::cin, npi);

    npi_parts = infix_to_npi_tokens(npi);

    std::cout << "NPI expression: ";
    print_npi_expression(npi_parts);
    
    std::cout << "Result: " << npi_evaluate(npi_parts) << std::endl;

    return 0;
}