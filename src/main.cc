// Copyright 2019 Dylan Dsouza
#include <iostream>
#include <string>
#include "lib/interpreter/include/interpreter.hpp"


int main(int argc, char const *argv[]) {
    std::string text = "";
    while (true) {
        std::cout << "calc> ";
        std::cin >> text;
        if (text == "") {
            continue;
        }
        try {
            Interpreter interpreter = Interpreter(text);
            int result = interpreter.Expr();
            std::cout << result << std::endl;
        } catch (const std::runtime_error& error) {
            std::cout << "A runtime error occurred" << std::endl;
            break;
        }
    }
    return 0;
}
