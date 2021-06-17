#ifndef UTILRECORD_H
#define UTILRECORD_H

#include <iostream>
#include <vector>
#include <string>

#include "../../!includes/Utility/util.h"

using namespace  std;


class UtilRecord: public Util
{

public:

    UtilRecord( const vector<long> & v );

    // =========================================================
    // accessors

    /// \returns the value of mem var _input
    vector<long> get_value( ) const;

    /// a virtual fiction that'll return the type of utilrecord
    virtual UTYPE get_type( );

    // =========================================================
    // display

    /// virtual function that'll print current vector
    virtual void print( ) ;


private:

    std::vector<long> _vec ;

};

#endif // UTILRECORD_H
