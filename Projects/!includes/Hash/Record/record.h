#ifndef RECORD_H
#define RECORD_H

#include <iomanip>
#include <iostream>

using namespace  std;

template  <typename T>
struct record
{
    int _key;
    T _value;

    record(int k = 0, T v = T()):_key(k), _value(v)
    {
    }

    friend bool operator ==(const record& left, const record& right) {
        if( left._key == right._key )
            return true;

        return false;
    }

    friend bool operator > (const record& left, const record& right) {
        if( left._key > right._key )
            return true;

        return false;
    }

    friend bool operator < (const record& left, const record& right) {
        if( left._key < right._key )
            return true;

        return false;
    }

    friend ostream& operator <<(ostream& outs, const record& print_me) {
        outs << setw(4) << setfill('0') << print_me._key << ":"
             << setw(4) << setfill('0') << print_me._value ;
        return outs;
    }
};
#endif // RECORD_H
