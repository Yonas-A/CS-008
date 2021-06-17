#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <vector>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Table/table.h"


class RPN
{
public:

    // ==============================================================
    // constructors

    /// a default ctor
    RPN( );

    /// a ctor with a string of tokens that have already been set into
    /// postfix expressions by Shunting Yard class
    RPN( Queue<ShuntingYardTokens::Token*> input );

    // ==============================================================
    // modifiers

    /// an operator that will return a vector of record numbers
    /// for the table database use
    vector<long>  operator ( ) ( Table& t );

    // ==============================================================
    // insertion operators and displays

    /// writes the private member variable _rpn's all value onto the console
    friend ostream& operator << ( ostream& outs, const RPN& value)
    {
        outs << value._rpn<< endl;
        return outs;
    }

private:

    /// holds string tokens that have already been converted to postfix
    /// expressions by the Shunting yard class/
    Queue< ShuntingYardTokens::Token*> _rpn;
};

#endif // RPN_H
