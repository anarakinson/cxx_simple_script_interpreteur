#include "lexer.h"

#include <cctype>


Lexer::Token Lexer::next_token() {

    while (true) {

        switch (m_state) {
        case State::End:
            return Token::End;
        case State::ReadNumber:
            if (end()) {
                m_state = State::End;
                return Token::Number;
            }
            
        }

    }

}