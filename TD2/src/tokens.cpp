#include "tokens.hpp"

Token make_token(float value) {
    Token t;
    t.type = TokenType::OPERAND;
    t.value = value;
    return t;
}

Token make_token(Operator op) {
    Token t;
    t.type = TokenType::OPERATOR;
    t.op = op;
    return t;
}

std::vector<Token> tokenize(std::vector<std::string> const& s) {
    std::vector<Token> tokens;

    for(const auto& token : s) {
        if(token == "+") {
            tokens.push_back(make_token(Operator::ADD));
        } else if(token == "-") {
            tokens.push_back(make_token(Operator::SUB));
        } else if(token == "*") {
            tokens.push_back(make_token(Operator::MUL));
        } else if(token == "/") {
            tokens.push_back(make_token(Operator::DIV));
        } else if(token == "^") {
            tokens.push_back(make_token(Operator::POW));
        } else if(token == "(") {
            tokens.push_back(make_token(Operator::OPEN_PAREN));
        } else if(token == ")") {
            tokens.push_back(make_token(Operator::CLOSE_PAREN));
        } else {
            tokens.push_back(make_token(std::stof(token)));
        }
    }

    return tokens;
}

size_t operator_precedence(Operator const op) {
    if(op == Operator::ADD || op == Operator::SUB) {
        return 1;
    } else if(op == Operator::MUL || op == Operator::DIV) {
        return 2;
    } else if(op == Operator::POW) {
        return 3;
    } else {
        return 0;
    }
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression) {
    std::vector<Token> npi_tokens;
    std::stack<Operator> operators;

    std::istringstream iss(expression);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    std::vector<Token> infix_tokens = tokenize(tokens);

    for(std::vector<Token>::size_type i = 0; i < infix_tokens.size(); i++) {
        if(infix_tokens[i].type == TokenType::OPERAND) {
            npi_tokens.push_back(infix_tokens[i]);
        } else if(infix_tokens[i].op == Operator::OPEN_PAREN) {
            operators.push(infix_tokens[i].op);
        } else if(infix_tokens[i].op == Operator::CLOSE_PAREN) {
            while(operators.top() != Operator::OPEN_PAREN) {
                npi_tokens.push_back(make_token(operators.top()));
                operators.pop();
            }
            operators.pop();
        } else {
            while(!operators.empty() && operator_precedence(operators.top()) >= operator_precedence(infix_tokens[i].op)) {
                npi_tokens.push_back(make_token(operators.top()));
                operators.pop();
            }
            operators.push(infix_tokens[i].op);
        }
    }

    while(!operators.empty()) {
        npi_tokens.push_back(make_token(operators.top()));
        operators.pop();
    }

    return npi_tokens;
}

float npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> stack;

    for(std::vector<Token>::size_type i = 0; i < tokens.size(); i++) {
        if(tokens[i].type == TokenType::OPERAND) {
            stack.push(tokens[i].value);
        } else if (stack.size() >= 2) {
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
            stack.pop();

            if(tokens[i].op == Operator::ADD) {
                stack.push(leftOperand + rightOperand);
            } else if(tokens[i].op == Operator::SUB) {
                stack.push(leftOperand - rightOperand);
            } else if(tokens[i].op == Operator::MUL) {
                stack.push(leftOperand * rightOperand);
            } else if(tokens[i].op == Operator::DIV) {
                stack.push(leftOperand / rightOperand);
            } else if(tokens[i].op == Operator::POW) {
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