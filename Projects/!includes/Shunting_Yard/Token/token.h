#ifndef SHUNTING_YARD_TOKENS_H
#define SHUNTING_YARD_TOKENS_H

#include <iostream>
#include <string>

/// Shy_tk
/// Sto_tk


namespace ShuntingYardTokens
{


enum class TokenType:int { words = 0, numbers = 1, variables = 2, operators = 3,
                           lparenthesis = 4, rparenthesis = 5 };

class Token
{

public:

    // =======================  ctor's  ========================

    ////////////////////////////////////////////////////////////
    /// \brief default Construct creates an empty token
    ///
    ////////////////////////////////////////////////////////////
    Token( );

    ////////////////////////////////////////////////////////////
    /// \brief Construct Token from a type string
    ///
    /// \param string assigned to member variable _input
    ///
    ////////////////////////////////////////////////////////////
    Token( const std::string& str );



    // ======================= accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the Token
    ///
    /// \return a string representing Token
    ///
    ////////////////////////////////////////////////////////////
    std::string get_token( );

    ////////////////////////////////////////////////////////////
    /// \brief Get the Token's token
    ///
    /// \return an enumeration tokenType that is associated with
    ///         a TokenType of Number
    ///
    ////////////////////////////////////////////////////////////
    virtual ShuntingYardTokens::TokenType get_type( );


    ////////////////////////////////////////////////////////////
    /// \brief remove quotations marks around string str
    ///
    /// \return a string without any quotation mark characters
    ///         around it
    ///
    ////////////////////////////////////////////////////////////
    std::string remove_quotations( const std::string& str );



    // ======================= display =========================

    ////////////////////////////////////////////////////////////
    /// \brief print Token onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print( ) ;

    ////////////////////////////////////////////////////////////
    /// \brief write to screen Token p's Token
    ///
    ////////////////////////////////////////////////////////////
    friend std::ostream& operator <<( std::ostream& outs,
                                 ShuntingYardTokens::Token* n_ptr);


private:

    /// a string that'll hold Token
    std::string _input;

};



}



#endif // SHUNTING_YARD_TOKENS_H
