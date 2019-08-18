// Copyright 2019 Dylan Dsouza
#include <stdexcept>
#include "include/interpreter.hpp"

Interpreter::Interpreter(std::string text) {
    this->text_ = text;
    this->current_character_ = this->text_[this->pos_];
    this->current_token_ = Token(TokenType::NONE, NULL);
}

void Interpreter::Error() {
    throw std::runtime_error("Invalid Syntax");
}

void Interpreter::Advance() {
    this->pos_ += 1;
    if (this->pos_ > this->text_.length() - 1) {
        this->current_character_ = NULL;
    } else {
        this->current_character_ = this->text_[this->pos_];
    }
}

void Interpreter::SkipWhitespace() {
    while (this->current_character_ != NULL
    && isspace(this->current_character_)) {
        this->Advance();
    }
}

int Interpreter::Integer() {
    std::string result = "";
    while (this->current_character_ != NULL
    && isdigit(this->current_character_)) {
        result += this->current_character_;
        this->Advance();
    }
    return std::stoi(result);
}

Token Interpreter::GetNextToken() {
    while (this->current_character_ != NULL) {
        if (isspace(this->current_character_)) {
            this->SkipWhitespace();
            continue;
        }

        if (isdigit(this->current_character_)) {
            return Token(TokenType::INTEGER, this->Integer());
        }

        if (this->current_character_ == '+') {
            this->Advance();
            return Token(TokenType::PLUS, '+');
        }

        if (this->current_character_ == '-') {
            this->Advance();
            return Token(TokenType::MINUS, '-');
        }

        this->Error();
    }

    return Token(TokenType::EOFT, NULL);
}

void Interpreter::Eat(TokenType token_type) {
    if (this->current_token_.GetType() == token_type) {
        this->current_token_ = this->GetNextToken();
    } else {
        this->Error();
    }
}

int Interpreter::Expr() {
    this->current_token_ = this->GetNextToken();
    Token left = this->current_token_;
    this->Eat(TokenType::INTEGER);

    Token op = this->current_token_;
    if (op.GetType() == TokenType::PLUS) {
        this->Eat(TokenType::PLUS);
    } else {
        this->Eat(TokenType::MINUS);
    }

    Token right = this->current_token_;
    this->Eat(TokenType::INTEGER);

    int result = 0;

    if (op.GetType() == TokenType::PLUS) {
        result = left.GetValue() + right.GetValue();
    } else {
        result = left.GetValue() - right.GetValue();
    }

    return result;
}
