// Copyright 2019 Dylan Dsouza
#include "include/token.hpp"

Token::Token() {
    this->type_ = TokenType::NONE;
    this->value_ = 0;
}

Token::Token(TokenType type, int value) {
    this->type_ = type;
    this->value_ = value;
}

TokenType Token::GetType() {
    return this->type_;
}

int Token::GetValue() {
    return this->value_;
}
