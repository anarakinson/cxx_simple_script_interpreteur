#include <interpreteur_tests.h>

#include <iostream>
#include <string>
#include <algorithm>


void Tests::parser_test() {
    
    std::cout << "START" << std::endl;

    Lexer lexer{};
    Parser parser{};


    std::wstring examples[] = {
        L"", 
        L"1", 
        L"1 + 2", 
        L"(1 + 2) * 3"
    };

    for (const auto &exam : examples) {
        Tokens tokens = lexer.tokenize(exam);

        Tokens parsed = parser.parse(tokens);

        if (tokens.empty()) {
            std::cout << "empty" << std::endl;
        }
        else {
            for (const auto &token : parsed) {
                TokenType type = token.type();
                std::wstring data = token.data();
                std::wcout << data << L" - ";
                std::cout << get_type(type) << " ; ";
            }
            std::cout << std::endl;
        }
    }
}