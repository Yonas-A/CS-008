
#include <iomanip>
#include <iostream>


#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Shunting_Yard/Token/number.h"
#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/left_paren.h"
#include "../../!includes/Shunting_Yard/Token/right_paren.h"


using namespace ShuntingYardTokens;

//using namespace std;

// a simple test for shunting yard

void shuntingYard_test( );
// a simple test for shunting yard

void tokenizer_test( );
// a simple test for tokenizer class

int main()
{

//    shuntingYard_test( );


    tokenizer_test();



    return 0;
}



void shuntingYard_test( )
{
    Queue<Token*> temp;

    /// Last < "Jones" or Age > 27 and Gender = M
    /// Select * where ( Last = \"Jack\" && "
    /// "Age == 24 ) || Age >= 34
    ///

    temp.Push( new class Left_Paren ("("));
    temp.Push( new  Token ("Last") );
    temp.Push( new class Operator ("<"));
    temp.Push( new  Token ("\"Jones\""));
    temp.Push( new class Operator ("||"));

    temp.Push( new  Token ("Age"));
    temp.Push( new class Operator (">"));
    temp.Push( new  Token ("27"));

    temp.Push( new class Right_Paren (")"));

    temp.Push( new class Operator ("&&"));
    temp.Push( new  Token ("Gender"));
    temp.Push( new class Operator ("="));
    temp.Push( new  Token ("M"));



    Queue<Token*> q;
    Shunting_Yard input(temp);
    cout << "Shunting Yard: " << input << endl;
    q = input.Post_Fix();
    cout << endl << "input.Post_Fix(): "<< endl << q << endl;
    cout << std::setfill('=')  << setw( 80 ) << "=" << endl;


}

void tokenizer_test( )
{
    vector<string> vec =
    { "Last" ,">" , "John" , "OR", "Age" , ">", "23"};

    for ( size_t i = 0; i < vec.size( ); i++ )
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;;

    Shunting_Yard sh ;
    sh.set_conditions( vec );

    cout << "Post fix: " <<  sh.Post_Fix() << endl << endl;

    vector<string> vec2 =
    { "last" ,"=" , "Van Gogh" , "OR", "Last" , "=", "Jackson", "and", "salary",
      ">=", "165000"};



    for ( size_t i = 0; i < vec2.size( ); i++ )
    {
        cout << vec2[i] << " ";
    }
    cout << endl << endl;
    sh.set_conditions( vec2 );

    cout << "Post fix: " <<  sh.Post_Fix() << endl << endl;


}


