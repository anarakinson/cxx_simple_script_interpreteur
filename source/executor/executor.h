#pragma once 

#include <token.h>

#include <iostream>
#include <string>
#include <functional>
#include <map>


typedef long double custom_t;

class Executor {
public:
    Executor() {
        m_operations[L'+'] = [](const custom_t &a, const custom_t &b) constexpr { return a + b; };
        m_operations[L'-'] = [](const custom_t &a, const custom_t &b) constexpr { return a - b; }; 
        m_operations[L'*'] = [](const custom_t &a, const custom_t &b) constexpr { return a * b; };
        m_operations[L'/'] = [](const custom_t &a, const custom_t &b) constexpr { return a / b; }; 
    }

    std::wstring execute(const Tokens &tokens) {
        clear_stack();

        for (const Token &token : tokens) {
            if (token.type() == TokenType::Int || token.type() == TokenType::Float) {
                m_stack.push_back(token);
            }
            else if (token.type() == TokenType::Operator) {
                Token number2 = m_stack.back();
                m_stack.pop_back();
                Token number1 = m_stack.back();
                m_stack.pop_back();
                
                custom_t data = m_operations[token.to_operator()](stold(number1.data()), stold(number2.data()));
                TokenType type = TokenType::Float;

                Token result{type, std::to_wstring(data)}; 

                m_stack.push_back(result);
            }
        }
        std::wstring out;
        if (m_stack.empty()) { 
            std::cout << "empty" << std::endl; 
            out = L"empty";
        }
        else {
            out = m_stack.back().data();
        }
        // std::wstring out = L"0";
        return out;
    }

    void clear_stack() { m_stack.clear(); }

private:
    std::map<wchar_t, std::function<custom_t(const custom_t&, const custom_t&)>> m_operations{};
    Tokens m_stack{};


};