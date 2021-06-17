#include <iostream>
#include <string>

#include "../../!includes/Utility/util.h"


// =========================================================
// ctor's

/// sets _input to an empty string
Util::Util( )
{

}

Util::Util( const std::string& s ):_input( s)
{

}

// =========================================================
// accessors
/// return the value of the private mem varaible _input
std::string Util::get_value( ) const
{
    return _input;
}

UTYPE Util:: get_type( )
{
    /// \returns a number identifing what kind of token _input is
    return  static_cast<UTYPE>( UTYPE::Word );
}
// =========================================================
// display

void Util::print()
{
    cout << " " << _input << " " ;
}

ostream& operator <<( ostream& outs, Util* U)
{
    U->print( );
    return outs;
}
