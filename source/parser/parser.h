#pragma once

#include <token.h>

#include <iostream>


class Parser {
public: 

    Tokens parse(const Tokens &tokens) { 

        m_output.clear();
        m_stack.clear();

        for (const auto &token : tokens) {
            switch (token.type()) {
            case TokenType::Int: 
                m_output.push_back(token); 
                break;
            case TokenType::Operator: 
                if (
                    m_stack.empty() || 
                    get_priority(m_stack[m_stack.size() - 1]) < get_priority(token) || 
                    check_brace(token, Operator::LBrace)
                ) {
                    update_stack(token);
                }
                else if (
                    get_priority(m_stack[m_stack.size() - 1]) > get_priority(token) || 
                    check_brace(token, Operator::RBrace)
                ) {
                    m_output.push_back(m_stack.back());
                    m_stack.pop_back();
                    update_stack(token);
                }
                else {
                    m_output.push_back(token);
                }
                break;
            case TokenType::Name: 
                m_output.push_back(token); 
                break;
            }
        }
        // move operators from stack to output
        while (!m_stack.empty()) {
            m_output.push_back(m_stack.back());
            m_stack.pop_back();
        }

        return m_output;

    }

private:
    Tokens m_output{};
    Tokens m_stack{};

    int get_priority(const Token &token) {
        if (
            token.data()[0] == static_cast<wchar_t>(Operator::Div) ||
            token.data()[0] == static_cast<wchar_t>(Operator::Mul)
        ) { return 1; }
        return 0;
    }

    void update_stack(const Token &token) {
        if (
            !(token.data()[0] == static_cast<wchar_t>(Operator::RBrace)) &&
            !(token.data()[0] == static_cast<wchar_t>(Operator::LBrace)) 
        )
        m_stack.push_back(token); 
    }

    bool check_brace(const Token &token, const Operator &op) {
        return token.data()[0] == static_cast<wchar_t>(op);
    }

    int m_holdover = 0;

};