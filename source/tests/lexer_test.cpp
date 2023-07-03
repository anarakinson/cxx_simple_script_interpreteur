#include <interpreteur_tests.h>

#include <iostream>
#include <string>
#include <algorithm>


void Tests::lexer_test() {

    std::cout << "START" << std::endl;

    Lexer lexer{};
    Parser parser{};

    std::wstring examples[] = {
        L"123", 
        L"+", 
        L"ASDF", 
        L"M123", 
        L"123M+1   ) >=   102", 
        L"1.2 + asd * 2", 
        L"1.2.3.4", 
        L"\"1.2.3 + asd\" + 2 * asd"
    };

    for (const auto &exam : examples) {
        Tokens tokens = lexer.tokenize(exam);
        
        std::wcout << exam << L" >>> ";

        if (tokens.empty()) {
            std::cout << "empty" << std::endl;
        }
        else {
            for (const auto &token : tokens) {
                TokenType type = token.type();
                std::wstring data = token.data();
                std::wcout << data << L" - ";
                std::cout << get_type(type) << " ; ";
            }
            std::cout << std::endl;
        }
    }
}


std::string Tests::get_type(TokenType type) 
{
    switch (type) {
        case TokenType::Operator:
            return "operator";
            break;
        case TokenType::Int:
            return "integer";
            break;
        case TokenType::Float:
            return "float";
            break;
        case TokenType::Name:
            return "name";
            break;
        case TokenType::String:
            return "string";
            break;
        default:
            return "unknown";  
    }
}

