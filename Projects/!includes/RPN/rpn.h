#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <vector>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Table/table.h"

class RPN {
   public:
    // ========================  constructors ======================== 

    /**
     * @brief a default RPN::RPN constructor 
     */ 
    RPN();

    /**
     * @brief  a ctor with a string of tokens that have already been set into 
     * postfix expressions by Shunting Yard class
     * @param input a Queue of tokens 
     */
    RPN(Queue<ShuntingYardTokens::Token*> input);

    // ==========================  modifiers ========================== 

    /**
     * @brief an operator that will return a vector of record numbers for the
     *  table database use
     * @param t a table
     */ 
    vector<long> operator()(Table& t);

    // ========================  insertion operators ======================== 

    /**
     * @brief writes RPN::value's private member variable value onto the console
     * @param outs an ostream operator to display the value to the console
     * @param value the RPN varaiable that will be displayed to the console
     */ 
    friend ostream& operator<<(ostream& outs, const RPN& value) {
        outs << value._rpn << endl;
        return outs;
    }

   private:

    /**
     * @brief holds string tokens that have already been converted to postfix
     *  expressions by the Shunting yard class
     */ 
    Queue<ShuntingYardTokens::Token*> _rpn;
};

#endif  // RPN_H
