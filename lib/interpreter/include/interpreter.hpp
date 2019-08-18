// Copyright 2019 Dylan Dsouza
#include <string>
#include "lib/token/include/token.hpp"

#ifndef LIB_INTERPRETER_INCLUDE_INTERPRETER_HPP_
#define LIB_INTERPRETER_INCLUDE_INTERPRETER_HPP_

class Interpreter {
 private:
    int pos_ = 0;
    std::string text_;
    Token current_token_;
    char current_character_;
 public:
    explicit Interpreter(std::string text);
    Token GetNextToken();
    void Advance();
    void SkipWhitespace();
    int Integer();
    void Eat(TokenType token_type);
    void Error();
    int Expr();
};

#endif  // LIB_INTERPRETER_INCLUDE_INTERPRETER_HPP_
