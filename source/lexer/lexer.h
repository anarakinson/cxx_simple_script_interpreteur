#pragma once

#include "token.h"

#include <iostream>
#include <vector>
#include <algorithm>


typedef std::vector<Token> Tokens;

class Lexer {
public:

    inline Tokens tokenize(const std::wstring &expr) {
        Tokens tokens{};
        
        if (!expr.empty()) { 
            std::wstring word = L"";
            TokenType type = TokenType::Unknown;

            for (const wchar_t &ch : expr) {

                if (!parsing_string) {
                    if (is_operator(word)) {
                        type = TokenType::Operator;
                        tokens.push_back(Token{type, word});
                        word = L"";
                    }
                    else if (ch == L' ' && !word.empty()) {
                        if (type != TokenType::String) { type = get_type(word); }
                        tokens.push_back(Token{type, word});
                        word = L"";
                    }
                    else if (ch == '"') {
                        parsing_string = true;
                        word += ch;
                    }
                    else {
                        word += ch;
                    }
                }
                else if (parsing_string) {
                    word += ch;
                    if (ch == '"') {
                        parsing_string = false;
                        type = TokenType::String;
                    }
                }
            }
            if (!word.empty()) {
                type = get_type(word);
                tokens.push_back(Token{type, word});
            }
        }
        return tokens;
    }

private:
    TokenType get_type(std::wstring word) {
        TokenType out = TokenType::Unknown;
        // check integer
        if (std::all_of(word.cbegin(), word.cend(), std::isdigit)) {
            out = TokenType::Int;
        }
        // check name
        else if (!std::isdigit(word[0])) {
            out = TokenType::Name;
        } 
        // check float
        else if (std::isdigit(word[0])) {
            bool correct = true;
            for (const wchar_t ch : word) {
                if (ch == '.' && correct) {
                    correct = false;
                    out = TokenType::Float;
                } else if (!isdigit(ch)) {
                    out = TokenType::Unknown;
                    break;
                }
            }
        }

        return out;
    }

    bool parsing_string = false;
};


