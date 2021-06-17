#ifndef RPN_TEST_H
#define RPN_TEST_H

#include <iostream>

#include <math.h>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/RPN/rpn.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Shunting_Yard/Token/left_paren.h"
#include "../../!includes/Shunting_Yard/Token/number.h"
#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/right_paren.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/STokenizer/stokenizer.h"
#include "../../!includes/Table/table.h"
#include "../../!includes/Token/token_strings.h"



void stokenizer_test( );

void shuntingYard_test( );

void rpn_test( );

void shuntingYard_RPN( );



void stokenizer_test ( )
{
    cout << "\n\n=  =   =   =   = STOKENIZER TEST =  =   =   =   =   =\n";

    char s[] = "Last = \"John\" and First = \"Smith\"";

    STokenizer stk( s );
    StokenizerTokens::Token t;
    int count = 0;
    stk >> t;
    while(  !stk.done() )
    {
        if ( t.get_type() !=
             static_cast<int>( StokenizerTokens::TokenType::WHITESPACE ))
            cout << count++ << "    " <<  t  << endl;

        stk >> t;
    }

    cout << "\n=  =   =   = EXITING STOKENIZER TEST =  =   =   =   =\n";

}

void shuntingYard_test( )
{

    cout << "=  =   =   =   =    SHUNTING && RPN TEST =  =   =   =  =   =\n";

    vector<string> vec =
    { "dep" ,"=" , "cs" , "OR", "year" , ">", "2014",
      "&&", "year", "<", "2018", "or", "Salary" , ">=", "240"};
//    dep = CS or year >2014 and year < 2018 or salary >= 242000

    for ( size_t i = 0; i < vec.size( ); i++ )
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;;

    Shunting_Yard sh ;
    sh.set_conditions( vec );

    cout << "BEFORE Post fix: " <<  sh.Post_Fix() << endl << endl;

    Queue<ShuntingYardTokens::Token*> postfix = sh.Post_Fix();

    cout << "AFTER Post fix: " <<  sh.Post_Fix() << endl << endl;


    RPN temp( sh.Post_Fix() );
    Table t("employee");
    vector<long> y = temp( t );

    cout << "RPN: " << temp << endl;
    for ( size_t i = 0; i < y.size() ;  i++ )
    {
        cout << y[i] << "    " ;
    }
    cout << endl;

    cout << "\n=  =   =   =   = EXITING SHUNTING && RPN TEST =   =   =   = \n";

}

void rpn_test( )
{
    Queue<ShuntingYardTokens::Token*> postfix;
    postfix.Push( new  ShuntingYardTokens::Token ("Last"));
    postfix.Push( new  ShuntingYardTokens::Token ("Jones"));
    postfix.Push( new class Operator ("=="));

    postfix.Push( new  ShuntingYardTokens::Token ("Age"));
    postfix.Push( new  ShuntingYardTokens::Token ("20"));
    postfix.Push( new class Operator (">="));

    postfix.Push( new  ShuntingYardTokens::Token ("Age"));
    postfix.Push( new  ShuntingYardTokens::Token ("30"));
    postfix.Push( new class Operator ("<="));

    postfix.Push( new class Operator ("||"));
    postfix.Push( new class Operator ("||"));



    RPN temp( postfix );
    Table t("employee");
    vector<long> y = temp( t );

    cout << "RPN: " << temp << endl;
    for ( size_t i = 0; i < y.size() ;  i++ )
    {
        cout << y[i] << "    " ;
    }
    cout << "=  =   = EXITING RPN TEST =   =   =   =\n";

}

void shuntingYard_RPN( )
{
    cout << "=  =   = shuntingYard_RPN TEST =   =   =   =\n";


    Queue<ShuntingYardTokens::Token*> temp;

    temp.Push( new  ShuntingYardTokens::Token ("First") );
    temp.Push( new class Operator ("=="));
    temp.Push( new  ShuntingYardTokens::Token ("\"Del Rio\""));
    temp.Push( new class Operator ("||"));
    temp.Push( new class Left_Paren ("("));
    temp.Push( new  ShuntingYardTokens::Token ("Age"));
    temp.Push( new class Operator (">="));
    temp.Push( new  ShuntingYardTokens::Token ("20"));
    temp.Push( new class Operator ("oR"));
    temp.Push( new  ShuntingYardTokens::Token ("Age"));
    temp.Push( new class Operator ("<="));
    temp.Push( new  ShuntingYardTokens::Token ("30"));
    temp.Push( new class Right_Paren (")"));


    Queue<ShuntingYardTokens::Token*> q;
    Shunting_Yard input(temp);
    cout << "Shunting Yard: " << endl << input << endl;

    q = input.Post_Fix();

    cout << endl << "Post_Fix(): "<< endl << q << endl;



    RPN rpn( q );
    Table t("employee");
    cout << t << endl << endl;

    vector<long> y = rpn( t );
    cout << "RPN: " << rpn << endl;

    cout << endl << endl;
    cout << "y.size( ): " << y.size()  << endl;
    for ( size_t i = 0; i < y.size() ;  i++ )
    {
        cout << y[i] << "    " ;
    }


    cout << "=  =   = EXITING shuntingYard_RPN TEST =   =   =   =\n";
}


#endif // RPN_TEST_H
