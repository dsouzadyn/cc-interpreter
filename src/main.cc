// Copyright 2019 Dylan Dsouza
#include <iostream>
#include <string>
#include "lib/interpreter/include/interpreter.hpp"


int main(int argc, char const *argv[]) {
    std::string text = "";
    while (!std::cin.eof()) {
        std::cout << "calc> ";
        getline(std::cin, text);
        if (text == "") {
            continue;
        }
        try {
            Interpreter interpreter = Interpreter(text);
            int result = interpreter.Expr();
            std::cout << result << std::endl;
        } catch (const std::runtime_error& error) {
            std::cerr << error.what() << std::endl;
            return -1;
        }
    }
    return 0;
}
