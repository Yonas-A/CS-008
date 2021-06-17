#ifndef FUNCTION_H
#define FUNCTION_H

#include <string.h>

#include <iostream>

#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/token.h"

using namespace std;

/// my namespace to differentiate between shunting yard tokens
/// and string tokenizer tokens

using namespace ShuntingYardTokens;

class Function : public Operator {
   public:
    Function(string str);

    string get_operator();

    //    int get_precedence() const;
    ////    // retruns the precedence of

   private:
    string _function;

    //    int _precedence;
};

#endif  // FUNCTION_H
