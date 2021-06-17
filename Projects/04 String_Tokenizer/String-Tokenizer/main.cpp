
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../../!includes/STokenizer/stokenizer.h"
#include "../../!includes/Token/token_strings.h"

using namespace std;


int main()
{
    char str[] = "Select * where, (Last = 'jack' && "
                 " Age == 24) || ''Age' >= 34.4 it's \n \"Samuel L.\""
                 " and \"Marry Ann\" Mr. Cooper \"Mar\". ";

/*
    char  str[] = "The idea that the midwife had 'returned' for the child"
                  " during the night gave him a pause of rest in which to"
                  " think. He sank into the rocking chair, the same one "
                  "in which Rebeca had sat during the early days of the "
                  "house to give embroidery lessons, and in which "
                  "Amaranth had played Chinese checkers with Colonel"
                  " Gerineldo Marquez, and in which Amaranth Ursula has"
                  " sewn the tiny clothing for the child , and in that"
                  " flash of lucidity he became aware that he was unable"
                  " to bear in his should the crushing weight of so "
                  "much past .";
*/

    cout << str << endl;
    cout << endl << "Length: " << strlen( str ) << endl << endl;;
    cout << "= = = = = = = = = = =   GO   = = = = = = = = = = = " << endl;


    STokenizer stk( str );
    StokenizerTokens::Token t;
    int count = 0;
    stk >> t;
    while( !stk.done() )
    {
        if ( t.get_type() !=
             static_cast<int>(StokenizerTokens::TokenType::WHITESPACE)  )
            cout << count++ << "    " << t  << endl;

        if ( count == 21 )
        {

        }
        stk >> t;
    }
    cout << "= = = = = = = = = = =   END   = = = = = = = = = = = " << endl;

    return 0;
}






