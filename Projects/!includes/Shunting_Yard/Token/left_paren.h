#ifndef LEFT_PAREN_H
#define LEFT_PAREN_H

#include <iostream>

#include <string.h>

#include "../../!includes/Shunting_Yard/Token/token.h"


class Left_Paren: public ShuntingYardTokens::Token
{
public:

    // ========================= ctor's ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct Left Parenthesis from a string
    ///
    /// \param string assigned to member variable _l_parentheis
    ///
    ////////////////////////////////////////////////////////////
    Left_Paren( std::string str );



    // ======================== accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the left Parenthesis
    ///
    /// \return Left Parenthesis as a string
    ///
    ////////////////////////////////////////////////////////////
    std::string get_Left_Paren( );

    ////////////////////////////////////////////////////////////
    /// \brief Get Left Parenthesis' token type
    ///
    /// \return an enumeration tokenType that is associated with
    ///         a TokenType of left Parenthesis
    ///
    ////////////////////////////////////////////////////////////
    virtual ShuntingYardTokens::TokenType get_type( ) override;



    // ======================== display =======================

    ////////////////////////////////////////////////////////////
    /// \brief print Left Parenthesis onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print ( ) override;


private:

    /// a string that'll hold left parenthesis
    std::string _l_parenthesis;

};

#endif // LEFT_PAREN_H
