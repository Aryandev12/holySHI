#ifndef LEXER_H
#define LEXER_H

#include <string>

// TokenType enum definition
enum TokenType {
    Keyword,
    Identifier, // variable
    Assignment,
    Number,
    String,
    Plus,
    Minus,
    Multiply,
    Divide,
    Modulus,
    Equal,
    LessThan,
    GreaterThan,
    LessEqual,
    LParen,
    RParen,
    Eol,
    // more if needed
};

// lexer struct definition
struct lexer {
    TokenType tokenType;
    std::string tokenValue;
};

#endif // LEXER_H
