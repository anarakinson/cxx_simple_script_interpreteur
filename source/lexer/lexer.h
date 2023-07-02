#pragma once

#include "token.h"

#include <iostream>
#include <vector>
#include <algorithm>


typedef std::vector<Token> Tokens;

class Lexer {
public:
    Lexer() {
        std::cout << "lexer" << std::endl;
    }


    inline Tokens tokenize(const std::wstring &expr) {
        Tokens tokens{};
        if (expr.empty()) { 
            return tokens;
        }
        else {
            std::wstring word = L"";
            TokenType type = TokenType::Unknown;
            for (const wchar_t &ch : expr) {
                if (is_operator(ch)) {
                    type = TokenType::Operator;
                    word += ch;
                    tokens.push_back(Token{type, word});
                    word = L"";
                }
                else if (ch == L' ' && !word.empty()) {
                    type = get_type(word);
                    tokens.push_back(Token{type, word});
                    word = L"";
                }
                else {
                    word += ch;
                }
            }
            if (!word.empty()) {
                type = get_type(word);
                tokens.push_back(Token{type, word});
            }
            return tokens;
        }
    }

private:
    TokenType get_type(std::wstring word) {
        if (std::all_of(word.cbegin(), word.cend(), std::isdigit)) {
            return TokenType::Int;
        } 
        else if (!std::isdigit(word[0])) {
            return TokenType::Name;
        } 
        else {
            return TokenType::Unknown;
        }
    }
};


