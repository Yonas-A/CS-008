

#include "../../!includes/Shunting_Yard/Token/function.h"

#include "../../!includes/Shunting_Yard/Token/operator.h"

Function::Function(string s) : Operator(s), _function(s) {
    /// removes quotations if there happens to be quotation around s
    _function = remove_quotations(s);
}

string Function::get_operator() {
    return _function;
}

//int Function::get_precedence() const
//{
//    return _precedence;
//}
