#pragma once

#include <token.h>

#include <iostream>


class Parser {
public:

    Tokens parse(const Tokens &tokens) { 
        Tokens output{};
        Tokens stack{};

        auto pop_all = [&]() { while(!stack.empty()) {
            output.push_back(stack.back());
            stack.pop_back();
        }};

        for(const Token &token : tokens) {
            if(token.type() == TokenType::Operator) {
                pop_all();
                stack.push_back(token);
                continue;
            }
            output.push_back(token);
        }
        pop_all();

        return output; 
    }

private:
    void set_priority(Token token) {

        switch (token.type()) {
            case TokenType::Operator
        }

    }

};