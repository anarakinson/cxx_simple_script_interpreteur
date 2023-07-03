#include "lexer.h"
#include <token.h>


#include <iostream>
#include <set>
#include <algorithm>


// convert string to vector of tokens
Tokens Lexer::tokenize(const std::wstring &expr) {
    Tokens tokens{};
    
    // if string is empty - return empty vector
    if (!expr.empty()) { 
        std::wstring word = L"";
        TokenType type = TokenType::Unknown;

        for (const wchar_t &ch : expr) {
            
            // if space or operator:
            // convert string to token
            // and add it to vector
            if (ch == L' ' || is_operator(ch)) {
                if (!word.empty()) {
                    type = get_token_type(word);
                    tokens.push_back(Token{type, word});
                    word = L"";
                }
                // if space - nothing to do, else if operator - add it to vector
                if (ch != L' ') {
                    tokens.push_back(Token{TokenType::Operator, std::wstring{ch}});
                }
            }
            // add new char to token
            else {
                word += ch;
            }

        }
        // get the last token
        if (!word.empty()) {
            type = get_token_type(word);
            tokens.push_back(Token{type, word});
        }
    }
    return tokens;
}


// get tokentype from string
TokenType Lexer::get_token_type(std::wstring word) {

    TokenType out = TokenType::Unknown;
    
    // check integer
    if (std::all_of(word.cbegin(), word.cend(), std::isdigit)) {
        out = TokenType::Int;
    }
    // check name
    else if (!std::isdigit(word[0])) {
        out = TokenType::Name;
    } 
    // // check float
    // else if (std::isdigit(word[0])) {
    //     bool correct = true;
    //     for (const wchar_t ch : word) {
    //         if (ch == '.' && correct) {
    //             correct = false;
    //             out = TokenType::Float;
    //         } else if (!isdigit(ch)) {
    //             out = TokenType::Unknown;
    //             break;
    //         }
    //     }
    // }

    return out;

}


// check if char is operator
bool Lexer::is_operator(wchar_t ch) {

    std::set<Operator> AllOperators = { 
        Operator::Plus, 
        Operator::Minus,
        Operator::Mul, 
        Operator::Div, 
        Operator::Equal, 
        Operator::Less, 
        Operator::More, 
        Operator::LBrace, 
        Operator::RBrace, 
        Operator::Quote, 
        Operator::Dot, 
        Operator::Comma, 
        Operator::Semicolon 
    };

    return AllOperators.count(static_cast<Operator>(ch));

}

