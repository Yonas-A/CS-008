#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <iostream>
#include <string>
#include <vector>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Stack/stack.h"

using namespace ShuntingYardTokens;

class Shunting_Yard {
   public:
    /// a ctor for shunting yard
    Shunting_Yard();

    Shunting_Yard(Queue<ShuntingYardTokens::Token*> input);

    Queue<ShuntingYardTokens::Token*> Post_Fix();

    void set_conditions(const vector<string>& vec);

    friend ostream& operator<<(ostream& outs, const Shunting_Yard& s) {
        outs << s._infix << endl;
        return outs;
    }

    /// \returns true if the occurrence of the first letter of str
    /// is found in string_type or
    /// \returns false;
    bool Find(string str, string string_type);

    ///finds the first letter of str  inside string find
    int FindNotAny(string str, string string_type);

   private:
    /// takes a vector of strings to be  passed through the
    /// shunting yard where as instead of givin an input queue, we
    /// give it a vector string and it tokenizes the string and returns
    /// postfix expression
    std::vector<std::string> _conditions;

    Queue<ShuntingYardTokens::Token*> _infix;

    /// \returns a tokenized queue after tokenizing vector of conditions
    void get_infix_tokens();

    /// \returns the token type of string str to given size;
    ShuntingYardTokens::TokenType type(string str);

    /// \returns true if str is an operator and not just any string
    ///  by comparing this str to the operators in the vector OPERATOR
    bool verify_operators(const string& str);
};

#endif  // SHUNTING_YARD_H
