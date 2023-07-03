#pragma once

#include <token.h>

#include <iostream>
#include <vector>
#include <algorithm>


class Lexer {
public:

    Tokens tokenize(const std::wstring &expr);

private:

    TokenType get_token_type(std::wstring word);
    bool is_operator(wchar_t ch);

};



