#include <iostream>
#include <iomanip>


#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/RPN/rpn_test.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Shunting_Yard/Token/left_paren.h"
#include "../../!includes/Shunting_Yard/Token/number.h"
#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/right_paren.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Shunting_Yard/Token/variable.h"
#include "../../!includes/STokenizer/stokenizer.h"
#include "../../!includes/Token/token_strings.h"

using namespace std;


//using namespace StokenizerTokens;
//using namespace ShuntingYardTokens;



int main()
{


//    shuntingYard_test();

//    stokenizer_test();

//    test_simple();

//    rpn_test();

    shuntingYard_RPN();


    return 0;
}
