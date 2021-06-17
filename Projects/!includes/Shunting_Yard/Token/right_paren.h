#ifndef RIGHT_PAREN_H
#define RIGHT_PAREN_H

#include <iostream>
#include <string>

#include "../../!includes/Shunting_Yard/Token/token.h"


class Right_Paren: public ShuntingYardTokens::Token
{
public:

    // ========================= ctor's ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct Right Parenthesis from a string
    ///
    /// \param string assigned to the member variable _r_parenthesis
    ///
    ////////////////////////////////////////////////////////////
    Right_Paren( std::string str );



    // ======================== accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the Right Parenthesis
    ///
    /// \return _r_parenthesis as a string
    ///
    ////////////////////////////////////////////////////////////
    std::string get_Right_Paren();

    ////////////////////////////////////////////////////////////
    /// \brief Get Right Parenthesis' token type
    ///
    /// \return an enumeration tokenType that is associated with
    ///         a TokenType of right Parenthesis
    ///
    ////////////////////////////////////////////////////////////
    virtual ShuntingYardTokens::TokenType get_type( ) override;



    // ======================== display =======================

    ////////////////////////////////////////////////////////////
    /// \brief print Right Parenthesis onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print ( ) override;


private:

    /// a string that'll hold right parenthesis
    std::string _r_parenthesis;

};

#endif // RIGHT_PAREN_H
