#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace  std;

class Record
{
public:

    Record(  );

    Record( char str[ ] );

    Record ( string s );


    long read( fstream& ins, long recno );

    long write( fstream& outs );

    friend ostream& operator << ( ostream& outs, const Record& r );
    
private:
    
    static const int MAX = 100;
    int _record_num ;
    char _record[ MAX ];
};

#endif // RECORD_H
