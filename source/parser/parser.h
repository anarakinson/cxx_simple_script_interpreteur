#pragma once

#include <token.h>

#include <iostream>


class Parser {
public:

    Tokens parse(const Tokens &tokens) { 

        Tokens output{};
        Tokens stack{};

        for (const auto &token : tokens) {
            switch (token.type()) {
            case TokenType::Int: 
                output.push_back(token); 
                break;
            case TokenType::Operator: 
                if (stack.empty()) {
                    stack.push_back(token); 
                }
                else if (
                    get_priority(stack[stack.size() - 1].data()) > get_priority(token.data()) || 
                    token.data()[0] == static_cast<wchar_t>(Operator::RBrace)
                ) {
                    output.push_back(stack.back());
                    stack.pop_back();
                    stack.push_back(token);
                }
                else if (
                    get_priority(stack[stack.size() - 1].data()) < get_priority(token.data()) || 
                    token.data()[0] == static_cast<wchar_t>(Operator::LBrace)
                ) {
                    stack.push_back(token);
                }
                else {
                    output.push_back(token);
                }
                break;
            case TokenType::Name: 
                output.push_back(token); 
                break;
            }
        }
        while (!stack.empty()) {
            output.push_back(stack.back());
            stack.pop_back();
        }

        return output;

    }

private:
    int get_priority(std::wstring data) {
        if (
            data[0] == static_cast<wchar_t>(Operator::Div) ||
            data[0] == static_cast<wchar_t>(Operator::Mul)
        ) { return 1; }
        return 0;
    }

    int m_holdover = 0;

};