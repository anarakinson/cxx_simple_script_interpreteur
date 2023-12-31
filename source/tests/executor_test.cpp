#include <interpreteur_tests.h>

#include <iostream>
#include <string>
#include <algorithm>


void Tests::executor_test() {
    
    std::cout << "START" << std::endl;

    Lexer lexer{};
    Parser parser{};
    Executor executor{};

    std::wstring examples[] = {
        L"", 
        L"1",                         // [ 1 ]
        L"1 + 2",                     // [ 1 2 + ]
        L"1 + 2 * 3",                 // [ 1 2 3 * + ]
        L"1 * 2 + 3",                 // [ 1 2 * 3 + ]
        L"(1 + 2) * 3",               // [ 1 2 + 3 * ]
        L"1 * 2 + 2 * 3",             
        L"1 * 2 - 2 * 3",             
        L"1 * 2 + 2 * 3 - 3 / 4",     // [ 1 2 * 2 3 * 3 4 / - + ]
        L"1 * (2 + 2) * (3 - 3) / 4"  // [ 1 2 * 2 3 * 3 4 / - + ]
    };

    for (const auto &exam : examples) {
        
        std::wcout << exam << std::endl;

        Tokens tokens = lexer.tokenize(exam);

        Tokens parsed = parser.parse(tokens);

        if (tokens.empty()) {
            std::cout << "empty" << std::endl;
        }
        else {
                std::cout << "[ ";
            for (const auto &token : parsed) {
                std::wstring data = token.data();
                std::wcout << data << L" ";
            }
            std::cout << "]" << std::endl;
        
            std::wstring computed = executor.execute(parsed);
            std::wcout << computed << std::endl;
        }
    }

}