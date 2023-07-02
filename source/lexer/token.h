#pragma once 


#include <string>

enum class TokenType {
    Operator,
    Int,
    Float,
    Name,
    Unknown,
};


enum class Operator : wchar_t {
    Plus = L'+',
    Minus = L'-',
    Product = L'*',
    Division = L'/',
};


class Token {
public:
    Token(TokenType type, std::wstring data) : m_type{type}, m_data{data} {}

    TokenType type() const { return m_type; }
    std::wstring data() const { return m_data; }

private: 
    TokenType m_type;
    std::wstring m_data;
};

bool is_operator(wchar_t ch) {
    switch (ch) {
        case Operator::Plus:
            return true;
            break;
        case Operator::Minus:
            return true;
            break;
        case Operator::Division:
            return true;
            break;
        case Operator::Product:
            return true;
            break;
        default:
            return false; 
    }
}