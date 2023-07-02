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


    inline Tokens tokenize(std::wstring expr) {
        if (expr.empty()){
            return {};
        }
        else if (std::all_of(expr.cbegin(), expr.cend(), std::isdigit)) {
            Token token{TokenType::Number, expr};
            return {token};
        }
        else if (std::any_of(expr.cbegin(), expr.cend(), is_operator)) {
            Token token{TokenType::Operator, expr};
            return {token};
        }
        else {
            Token token{TokenType::Name, expr};
            return {token};
        }
    }

};