#include "../../!includes/RPN/rpn.h"

#include <math.h>

#include <iostream>
#include <string>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Shunting_Yard/Token/left_paren.h"
#include "../../!includes/Shunting_Yard/Token/number.h"
#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/right_paren.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Sort/heap_sort.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Table/table.h"
#include "../../!includes/Union_n_Intersection/intersection.h"
#include "../../!includes/Union_n_Intersection/union.h"
#include "../../!includes/Union_n_Intersection/union_intersection_helper.h"
#include "../../!includes/Utility/util.h"
#include "../../!includes/Utility/utilrecord.h"

using namespace ShuntingYardTokens;

RPN::RPN() {
}

RPN::RPN(Queue<ShuntingYardTokens::Token*> input) : _rpn(input) {
}

vector<long> RPN::operator()(Table& t) {
    const bool DEBUG = false;

    Stack<Util*> record_keep;
    /// a stack that will store either strings of tokes as Util or
    /// vector of longs as UtilRecord

    Queue<ShuntingYardTokens::Token*> rpn_temp(_rpn);
    /// create a copy of current tokens using Queue's copy ctor

    while (!rpn_temp.Empty()) {
        Token* item = rpn_temp.Pop();

        /// \if current token from ShuntingYardTokens is words
        if (item->get_type() ==
            static_cast<TokenType>(TokenType::words)) {
            /// push this token into the stack
            string str = static_cast<Token*>(item)->get_token();
            record_keep.Push(new Util(str));
        }

        else if (item->get_type() ==
                 static_cast<TokenType>(TokenType::numbers)) {
            /// push this token into the stack as string
            double num = static_cast<Number*>(item)->get_num();
            record_keep.Push(new Util(to_string(num)));
        }

        else if (item->get_type() ==
                 static_cast<TokenType>(TokenType::operators)) {
            string hold = static_cast<Operator*>(item)->get_operator();

            if (hold == "<" || hold == "<=" || hold == "=" ||
                hold == ">" || hold == ">=" || hold == "==") {
                string rhs = static_cast<Util*>(record_keep.Pop())->get_value();
                string lhs = static_cast<Util*>(record_keep.Pop())->get_value();

                vector<long> vR = t.find_records(lhs, hold, rhs);
                /// find the records that satisfy these conditions and operator
                /// and push the returning vector as a vector of long
                record_keep.Push(new UtilRecord(vR));
            }

            else if (hold == "or" || hold == "||" ||
                     hold == "OR" || hold == "oR" || hold == "Or") {
                vector<long> rhs =
                    static_cast<UtilRecord*>(record_keep.Pop())->get_value();
                vector<long> lhs =
                    static_cast<UtilRecord*>(record_keep.Pop())->get_value();

                vector<long> v(rhs.size() + lhs.size());

                v = *Union(rhs, lhs);
                /// find the union of lhs & rhs and push it into the
                /// record keep as vector of long
                record_keep.Push(new UtilRecord(v));
            }

            else if (hold == "and" || hold == "And" ||
                     hold == "AND" || hold == "&&") {
                vector<long> rhs =
                    static_cast<UtilRecord*>(record_keep.Pop())->get_value();
                vector<long> lhs =
                    static_cast<UtilRecord*>(record_keep.Pop())->get_value();

                vector<long> v(rhs.size() + lhs.size());

                v = *Intersection(rhs, lhs);
                /// find the intersection on lhs and rhs and push the returning
                /// vector of long onto record_keep as a UtilRecord
                record_keep.Push(new UtilRecord(v));
            } else
                cout << "RPN::( )::Error:" << endl
                     << "processing:  " << item << endl;
        }
    }

    if (DEBUG) {
        cout << "RPN()::operator(): stack size: " << record_keep.Size() << endl;
        cout << " temp.rpn: " << rpn_temp << endl;
        cout << "_rpn: " << _rpn << endl;
    }

    vector<long> v = static_cast<UtilRecord*>(record_keep.Pop())->get_value();
    heapSort_function(&v);
    if (DEBUG)
        cout << "final RPN vector: " << endl
             << v << endl;
    return v;
}
