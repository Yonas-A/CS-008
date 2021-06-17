#ifndef MPAIR_H
#define MPAIR_H

#include <iostream>

#include "../../!includes/Array_Functions/array_functions.h"


using namespace std;


template <typename K, typename V>
struct MPair
{
    K key;
    vector<V> value_list;

    /// default CTOR with a key and no value: this will create an empty vector
    MPair( const K& k = K() ): key( k ) {

    }

    /// CTOR with a key AND a value: pushes the value into the value_list
    MPair(const K& k, const V& v): key ( k )
    {
        value_list += v;
    }

    /// CTOR with a key and a vector of values (to replace value_list)
    MPair(const K& k, const vector<V>& vlist): key( k )
    {
        value_list.clear();
        value_list += vlist ;
    }

    //You'll need to overlod << for your vector:
    friend ostream& operator << ( ostream& outs, const MPair<K, V>& p)
    {
        outs << left << setw(15) << p.key  << "\t" << setw( 5 )
             << "|" << right <<  p.value_list ;
        return outs;
    }

    friend bool operator == (const MPair<K, V>& lhs,
                                    const MPair<K, V>& rhs)
    {
        return ( lhs.key == rhs.key);

    }
    friend bool operator < (const MPair<K, V>& lhs,
                                    const MPair<K, V>& rhs)
    {
        return ( lhs.key < rhs.key);

    }
    friend bool operator > ( const MPair<K, V>& lhs,
                                    const MPair<K, V>& rhs)
    {
        return ( lhs.key > rhs.key);
    }

    friend bool operator <= ( const MPair<K, V>& lhs,
                                    const MPair<K, V>& rhs)
    {
        return ( lhs.key <= rhs.key);

    }

    friend bool operator >= ( const MPair<K, V>& lhs,
                                    const MPair<K, V>& rhs)
    {
        return ( lhs.key >= rhs.key);

    }
    friend MPair<K,V> operator + ( const MPair<K, V>& lhs,
                                        const MPair<K, V>& rhs)
    {
        assert ( lhs.key == rhs.key && "operator+ lhs.key != rhs.key");

        return (MPair <K, V> ( lhs.key, lhs.value_list + rhs.value_list ) );

    }
};

#endif // MPAIR_H
