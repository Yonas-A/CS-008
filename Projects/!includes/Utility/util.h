#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>

enum class UTYPE:int { Word = 0, LogicalOperator = 1 };


using namespace  std;

class Util
{
public:


    // =========================================================
    // ctor's

    Util();
    /// default Util ctor that'll set _input to an empty string

    /// a ctor with a string that the mem var _input will be set to
    Util( const std::string& s );

    // =========================================================
    // accessors

    /// \returns the value of mem var _input
    std::string get_value( ) const;

    /// a virtual fiction that'll return the type of token _input is
    virtual UTYPE get_type( );

    // =========================================================
    // display

    /// virtual function that'll print current token
    virtual void print( ) ;

    /// friend operator that'll print token U's mem var _input
    friend ostream& operator <<( ostream& outs, Util* U);

private:

    /// a string that'll hold a string which will be tokenized
    std::string _input;

};


#endif // UTIL_H
