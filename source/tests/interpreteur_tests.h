#pragma once 

#include <lexer.h>
#include <parser.h>
#include <executor.h>



namespace Tests {
    // lexer 
    std::string get_type(TokenType type);
    void lexer_test();

    // parser 
    void parser_test();

    // executioner 
    void executor_test();

} // end Tests
