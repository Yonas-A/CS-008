
#include "../../!includes/Shunting_Yard/Token/token.h"

#include <iostream>
#include <string>

namespace ShuntingYardTokens {

// =========================================================
// ctor's

/// sets _input to an empty string
ShuntingYardTokens::Token::Token() {
}

ShuntingYardTokens::Token::Token(const std::string& s) {
    /// removes quotations if there happens to be quotation around s
    _input = remove_quotations(s);
}

// =========================================================
// accessors

std::string ShuntingYardTokens::Token::get_token() {
    return _input;
}

ShuntingYardTokens::TokenType Token::get_type() {
    /// \returns a number identifying what kind of token _input is
    return static_cast<ShuntingYardTokens::TokenType>(ShuntingYardTokens::TokenType::words);
}
// =========================================================
// modifiers

std::string ShuntingYardTokens::Token::remove_quotations(const std::string& s) {
    std::string temp(s);
    if (temp[0] == '\"')
        temp.erase(0, 1);
    if (temp[temp.size() - 1] == '\"') {
        std::cout << "temp size: " << temp.size() << std::endl;
        temp.resize(temp.size() - 1);
    }

    return temp;
}

// =========================================================
// display

void ShuntingYardTokens::Token::print() {
    std::cout << " " << _input << " ";
}

std::ostream& operator<<(std::ostream& outs, ShuntingYardTokens::Token* p) {
    p->print();
    return outs;
}

}  // namespace ShuntingYardTokens
