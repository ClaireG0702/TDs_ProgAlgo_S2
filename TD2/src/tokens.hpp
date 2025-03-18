#pragma once

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <cctype>
#include <stack>
#include <cmath>

enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN };
enum class TokenType { OPERATOR, OPERAND };

struct Token {
    TokenType type;
    float value;
    Operator op;
};

Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const& s);
size_t operator_precedence(Operator const op);
std::vector<Token> infix_to_npi_tokens(std::string const& expression);
float npi_evaluate(std::vector<Token> const& tokens);
