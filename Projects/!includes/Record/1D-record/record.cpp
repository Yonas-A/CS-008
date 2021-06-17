#include <fstream>
#include <iomanip>
#include <iostream>

#include "../../!includes/Record/1D-record/record.h"

using namespace  std;

Record::Record(  )
{
    _record[ 0 ] = NULL;   /// _record[ 0 ] = '\0';
    _record_num = -1;
}

Record::Record( char str[ ] )
{
    strcpy( _record, str );
}

Record::Record ( string s )
{
    strcpy( _record, s.c_str(  ) );
}

long Record::read( fstream& ins, long recno )
{
    long pos = recno * sizeof( _record );
    ins.seekg( pos, ios_base::beg );

    ins.read( _record, sizeof( _record ) );
    return ins.gcount(  );
}

long Record::write( fstream& outs )
{
    //write to the end of the file.
    outs.seekg( 0, outs.end );
    long pos = outs.tellp(  );

    //outs.write( &record[0], sizeof( record ) );
    outs.write( _record, sizeof( _record ) );

    return pos/sizeof( _record );
}

ostream& operator << ( ostream& outs, const Record& r )
{
    outs << r._record;
    return outs;
}

