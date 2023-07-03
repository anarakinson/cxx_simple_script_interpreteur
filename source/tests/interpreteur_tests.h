#pragma once 

#include <lexer.h>
#include <parser.h>



namespace Tests {
    // lexer 
    std::string get_type(TokenType type);
    void lexer_test();

    // parser 
    void parser_test();

} // end Tests
