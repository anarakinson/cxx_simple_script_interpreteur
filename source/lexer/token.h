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


enum class Operator : wchar_t {
    Plus = L'+',
    Minus = L'-',
    Mul = L'*',
    Div = L'/',
    Equal = L'=',
    Less = L'>',
    More = L'<',
    LBrace = L'(',
    RBrace = L')',
    Quote = L'"',
    Dot = L'.',
    Comma = L',',
    Semicolon = L';',
};


class Token {
public:
    Token(TokenType type, std::wstring data) : m_type{type}, m_data{data} {}

    TokenType type() const { return m_type; }
    std::wstring data() const { return m_data; }

    void increase_priority(int value = 0) { m_priority += value; }
    int priority() { return m_priority; }

private: 
    TokenType m_type;
    std::wstring m_data;
    int m_priority = 0;
};

typedef std::vector<Token> Tokens;
