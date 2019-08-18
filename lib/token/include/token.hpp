// Copyright 2019 Dylan Dsouza
#ifndef LIB_TOKEN_INCLUDE_TOKEN_HPP_
#define LIB_TOKEN_INCLUDE_TOKEN_HPP_

enum TokenType {
    EOFT,
    INTEGER,
    PLUS,
    MINUS,
    NONE
};

class Token {
 private:
    TokenType type_;
    int value_;
 public:
    Token();
    Token(TokenType type, int value);
    TokenType GetType();
    int GetValue();
};

#endif  // LIB_TOKEN_INCLUDE_TOKEN_HPP_
