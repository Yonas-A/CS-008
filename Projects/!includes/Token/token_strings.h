#ifndef TOKEN_STRINGS_H
#define TOKEN_STRINGS_H

#include <iostream>
#include <string>

using namespace std;

namespace StokenizerTokens {

enum class TokenType : int { ALPHA = 5,
                             INTEGER = 10,
                             DOUBLE = 12,
                             WHITESPACE = 20,
                             PUNCTUATION = 25,
                             OPERATOR = 26 };

class Token {
   public:
    // =========================================================
    // ctor's

    /// default ctor with no paraments, _token set to empty string
    Token();

    /// a ctor with a string that the mem var _token will be set to
    Token(string str, int t);

    // =========================================================
    // accessors

    /// \returns the value of member variable _token as a string
    string get_string_token() const;

    /// \returns what token type current token is in integers
    int get_type() const;

    /// \returns what token type current token is in words
    string get_type_string() const;

    // =========================================================
    // insertion operator

    /// friend operator that'll print token t's member variable _token
    friend ostream& operator<<(ostream& outs,
                               const StokenizerTokens::Token& t);

   private:
    /// a string that'll hold a string which will be tokenized
    string _token;

    /// indicates what type of token current string is
    int _type;
};

}  // namespace StokenizerTokens

#endif  // TOKEN_STRINGS_H
