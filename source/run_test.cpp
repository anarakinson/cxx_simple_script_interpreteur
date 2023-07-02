#include <lexer.h>
#include <parser.h>

#include <iostream>
#include <string>
#include <algorithm>



void print_type(TokenType type) {
    switch (type) {
        case TokenType::Operator:
            std::cout << "operator" << std::endl;
            break;
        case TokenType::Number:
            std::cout << "number" << std::endl;
            break;
        case TokenType::Name:
            std::cout << "name" << std::endl;
            break;
        default:
            std::cout << "unknown" << std::endl;  
    }
}


int main() {

    std::cout << "START" << std::endl;

    Lexer lexer{};
    Parser parser{};

    std::wstring examples[] = {L"123", L"+", L"ASDF"};

    for (auto exam : examples) {
        Tokens tokens = lexer.tokenize(exam);
        
        Token token = tokens[0];
        TokenType type = token.type();
        
        std::wcout << exam << " - ";
        print_type(type);
    }
}
