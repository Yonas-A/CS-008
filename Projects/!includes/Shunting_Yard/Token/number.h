#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <string>

#include "../../!includes/Shunting_Yard/Token/token.h"


class Number: public ShuntingYardTokens::Token
{
public:

    // =======================  ctor's  ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct Number Class from a type double
    ///
    /// \param Double assigned to member variable _num
    ///
    ////////////////////////////////////////////////////////////
    Number( double number );

    ////////////////////////////////////////////////////////////
    /// \brief Construct  Number Class from a string
    ///
    /// \note for Database project only, if there happens to be
    ///       quotation around stirng s, remove the quotation
    ///       \example if s = "42.000" s should be 42.000
    ///
    /// \param string to be converted to a double and assigned to
    ///        member variable _num
    ///
    ////////////////////////////////////////////////////////////
    Number( std::string s );




    // ======================= accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the Number token
    ///
    /// \return Number as a type double
    ///
    ////////////////////////////////////////////////////////////
    double get_num( );

    ////////////////////////////////////////////////////////////
    /// \brief Get Number's token type
    ///
    /// \return an enumeration tokenType that is associated with
    ///         a TokenType of Number
    ///
    ////////////////////////////////////////////////////////////
    virtual ShuntingYardTokens::TokenType get_type( ) override;




    // ======================= display =========================

    ////////////////////////////////////////////////////////////
    /// \brief print Number onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print() override ;


private:

    /// a type double that'll hold Number
    double _num;

};

#endif // NUMBER_H
