#include "../../!includes/Shunting_Yard/shunting_yard.h"

#include <iostream>
#include <string>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Shunting_Yard/Token/left_paren.h"
#include "../../!includes/Shunting_Yard/Token/number.h"
#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/right_paren.h"
#include "../../!includes/Shunting_Yard/constants.h"
#include "../../!includes/Stack/stack.h"

//using namespace ShuntingYardTokens;

Shunting_Yard::Shunting_Yard() : _infix() {
}

Shunting_Yard::Shunting_Yard(Queue<ShuntingYardTokens::Token*> input)
    : _infix(input) {
}

Queue<ShuntingYardTokens::Token*> Shunting_Yard::Post_Fix() {
    /**
     * STEPS:
     * if token is number or variable push into postfix queue
     * if left paranthesis push it into operator stack
     * if Right_paren, while top of operator stack is not
            left_parenthesis, push operators into postfix queue
            pop the left parenthesis and discard it
     * if token is operator, while operator stack is not empty
     *     and top of operator stack is not left_parenthesis
     *     and top of operator stack has same or greater
     *                precedence as operator
     *     pop operator stack and push into postfix queue
     */

    Queue<ShuntingYardTokens::Token*> infix_temp = _infix;

    /// holds the post_fix expression
    Queue<ShuntingYardTokens::Token*> post_fix;
    /// hold operators while converting
    Stack<ShuntingYardTokens::Token*> operator_stack;

    while (!infix_temp.Empty()) {
        ShuntingYardTokens::Token* item = infix_temp.Pop();

        if (item->get_type() == static_cast<TokenType>(TokenType::numbers) ||
            item->get_type() == static_cast<TokenType>(TokenType::words)) {
            post_fix.Push(item);
        }

        else if (item->get_type() == static_cast<TokenType>(TokenType::operators)) {
            while (!operator_stack.Empty() && operator_stack.Top()->get_type() != static_cast<TokenType>(TokenType::lparenthesis) &&
                   (static_cast<Operator*>(operator_stack.Top())->get_precedence() >=
                    static_cast<Operator*>(item)->get_precedence())) {
                ShuntingYardTokens::Token* operands = operator_stack.Pop();
                post_fix.Push(operands);
            }

            operator_stack.Push(item);
        }

        else if (item->get_type() ==
                 static_cast<TokenType>(TokenType::lparenthesis)) {
            operator_stack.Push(item);
        }

        else if (item->get_type() ==
                 static_cast<TokenType>(TokenType::rparenthesis)) {
            while (operator_stack.Top()->get_type() !=
                   static_cast<TokenType>(TokenType::lparenthesis)) {
                ShuntingYardTokens::Token* operands = operator_stack.Pop();
                post_fix.Push(operands);
            }
            operator_stack.Pop();
        }
    }

    while (!operator_stack.Empty()) {
        if (operator_stack.Top()->get_type() ==
            static_cast<TokenType>(TokenType::lparenthesis)) {
            operator_stack.Pop();
        }

        else {
            ShuntingYardTokens::Token* operands = operator_stack.Pop();
            post_fix.Push(operands);
        }
    }

    return post_fix;
}

void Shunting_Yard::set_conditions(const std::vector<string>& vec) {
    _conditions.clear();
    _conditions = vec;
    get_infix_tokens();
}

bool Shunting_Yard::Find(string str, string string_type) {
    for (unsigned int i = 0; i < string_type.length(); i++) {
        /// if first letter of str is found in string_type
        if (str.front() == string_type[i])
            return true;
    }

    return false;
}

int Shunting_Yard::FindNotAny(string str, string string_type) {
    /*  STEPS
 *  iterate through the string str
 *  call find function to findfind the occurence
 *                  of str[i]in string_type
 *  if the consecutive letters belonge to same string_type
 *          continue
 *  else return position last letter belonging string_type
 *
 *  if by chance str has only one element and cant be iterated
 *      return -1 to identify that it is the last letter in str;
 */

    for (unsigned int i = 0; i < str.length(); i++) {
        string a;
        a = str.at(i);

        if (Find(a, string_type) == false)
            return i;
        else
            continue;
    }
    return -1;
    //had to figure out this after a very long debugging session
}

TokenType Shunting_Yard::type(string str) {
    if (Find(str, LEFTP)) {
        return TokenType::lparenthesis;
    } else if (Find(str, RIGHTP)) {
        return TokenType::rparenthesis;
    }

    else if (Find(str, OP)) {
        if (verify_operators(str))
            /// verifies if this string is in
            return TokenType::operators;
        else
            return TokenType::words;
    }

    else if (Find(str, NUM)) {
        //        return TokenType::numbers;
        /// \newcode
        return TokenType::words;
        /// for database since table only contains strings all types of
        /// numbers from console should be recognized as words
    } else if (Find(str, WORD)) {
        return TokenType::words;
    }

    else
        assert(false);
}

void Shunting_Yard::get_infix_tokens() {
    _infix.Clear();
    /// clear out anything that was previously in the infix queue
    Queue<ShuntingYardTokens::Token*> input;
    unsigned int i = 0;

    while (_conditions.size() > i) {
        string temp = _conditions[i];

        TokenType t_type = type(temp);
        switch (t_type) {
            case TokenType::words:
                input.Push(new Token(temp));
                break;

            case TokenType::lparenthesis:
                input.Push(new Left_Paren(temp));
                break;

            case TokenType::rparenthesis:
                input.Push(new Right_Paren(temp));
                break;

            case TokenType::operators:
                input.Push(new Operator(temp));
                break;

            case TokenType::numbers:
                input.Push(new Number(temp));
                break;
        }
        i++;
    }

    _infix = input;
}

bool Shunting_Yard::verify_operators(const string& str) {
    for (size_t i = 0; i < OPERATORS.size(); i++)
        if (str == OPERATORS[i])
            return true;
    return false;
}
