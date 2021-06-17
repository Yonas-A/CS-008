#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <string>

#include "../../!includes/Shunting_Yard/Token/token.h"
#include "../../!includes/Map/BPlus_Tree/map.h"

using namespace  std;

class Operator: public ShuntingYardTokens::Token
{
public:


    // ========================= ctor's ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct the operator from a string
    ///
    /// \param string  assigned to the member variable _operator
    ///
    ////////////////////////////////////////////////////////////
    Operator( std::string str );



    // ======================== accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the operator
    ///
    /// \return operator as a string
    ///
    ////////////////////////////////////////////////////////////
     std::string get_operator( );

    ////////////////////////////////////////////////////////////
    /// \brief get the operator's precedence
    ///
    /// \if current string does not have a precedence, it means that
    /// current string is not operator or does not qualify as an
    /// operator for our purpose
    ///
    /// \return an int identifying the current operators precedence
    ///
    ////////////////////////////////////////////////////////////
    int get_precedence( ) const;

    ////////////////////////////////////////////////////////////
    /// \brief get operator's token type
    ///
    /// \return an enumeration tokenType that is associated with
    /// a TokenType of operators
    ///
    ////////////////////////////////////////////////////////////
    virtual ShuntingYardTokens::TokenType get_type( ) override;



    // ======================== display =======================

    ////////////////////////////////////////////////////////////
    /// \brief print operator onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print( ) override ;

private:

    /// String to hold current operator
     std::string _operator;

    /// map to hold precedence for different operators
    Map < std::string, int > _precedence;



    // ======================== modifiers =======================

    ////////////////////////////////////////////////////////////
    /// \brief set a precedence as a number for different operators
    ///        based on standard mathimathical conventions such as
    ///        such as +, - , * ,etc ...
    ///
    ////////////////////////////////////////////////////////////
    void assign_precedence( );


};

#endif // OPERATOR_H
