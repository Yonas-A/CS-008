#include <iomanip>
#include <iostream>
#include <string>

#include "../../!includes/Token/token_strings.h"

using namespace  std;


/**
 * \attention \NEVER PUT A USING STATEMENT ACTUALLY IN A HEADER FILE
  * Sometimes a header file itself needs to use something from a
  * namespace. In this case, always use  use an item directly in a
  * program by preceding the item with the name of the namespace and
  *  “::” ; never put a using statement in a header file
  * (since doing so can have unexpected results in other programs that
  *  include the header file ).
  */

/**
 * ShuntingYardTokens: a namespace that encloses the class Token
 * which works with Stokenizer class that we defined for toknenizing
 * a given string into words, numbers, punctuations etc ...
 */
namespace StokenizerTokens
{

// =========================================================
// ctor's

/// sets _token to an empty string
StokenizerTokens::Token::Token( ): _token( ), _type( )
{

}
/// sets _token to s and _type to the value of t
StokenizerTokens::Token::Token( string s, int t ): _token(s), _type(t)
{

}

// =========================================================
// accessors


string StokenizerTokens::Token::get_string_token( ) const
{
    return _token;
}

int StokenizerTokens::Token::get_type( ) const
{
    return _type;
}

string StokenizerTokens::Token::get_type_string( ) const
{
    /// mostly used for debugging purposes
    /// \returns whether a token is double, integer, alpha ...
    switch ( _type )
    {
    case 5:
        return "ALPHA";
    case 10:
        if( _token.find('.')  !=  string::npos)
            return "DOUBLE";
        else
            return "INTEGER";
    case 20:
        return "SPACE";
    case 25:
        return "PUNCTUATION";
    case 26:
        return "OPERATOR";
    default:
        return "UNKNOWN";
    }
}

// =========================================================
// display
/// prints token t to the screen
ostream& operator <<( ostream& outs, const StokenizerTokens::Token& t )
{
    outs << left << setw(11) << t.get_type_string()<< right
         << setw(10) << "|" << t._token  << "|"  << endl;
    return outs;
}

}

