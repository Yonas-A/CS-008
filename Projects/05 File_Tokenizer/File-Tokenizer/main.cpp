/*
 * Author: Yonas Adamu
 * Project: FILE TOKENIZER
 * Purpose: using a state machine and a string tokenizer, write a program
 *          to tokenizer a file into several tokens (word, integers,
 *          doubles, punctuations, white spaces ...)
 */

#include <iostream>
#include <fstream>
#include "../../!includes/Token/token_strings.h"
#include "../../!includes/FTokenizer/ftokenizer.h"

using namespace std;

void test_FTokenize_simple();

int main()
{
    test_FTokenize_simple();

    return 0;
}


void test_FTokenize_simple()
{
    Token t;
    FTokenizer ftk("solitude.txt");

    int token_count = 0;
    ftk >> t;
    while ( ftk.more( ) )
    {
        if ( t.get_type_string() == "ALPHA" )
        {
            cout << left << setw(10) << token_count++ << setw(3) << left
                 << ":" << setw(25) << left << t;
        }
        if ( token_count == 2723 )
        {

        }

        ftk >> t;
    }

    cout << "Tokens Found: " << token_count << endl;
    cout << "= = = = = = = = = = = = = = = = = = = = = = =" << endl;

}
