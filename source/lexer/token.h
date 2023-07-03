#pragma once 


#include <string>
#include <vector>


enum class TokenType {
    Operator,
    Int,
    Float,
    String,
    Name,
    Unknown,
};


namespace Operator {
    std::wstring Plus = L"+";
    std::wstring Minus = L"-";
    std::wstring Product = L"*";
    std::wstring Division = L"/";

    std::vector values{
        Plus,
        Minus,
        Product,
        Division
    };
}; // end Operator


class Token {
public:
    Token(TokenType type, std::wstring data) : m_type{type}, m_data{data} {}

    TokenType type() const { return m_type; }
    std::wstring data() const { return m_data; }

private: 
    TokenType m_type;
    std::wstring m_data;
};

bool is_operator(const std::wstring &word) {
    for (const auto &op : Operator::values) {
        if (word == op) {
            return true;
        }
    }
    return false;
}