#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename K, typename V>
struct Pair
{
    K key;
    V value;

    /// default CTOR with a key and no value: this will create an empty vector
    Pair( const K& k = K(), const V& v = V() ): key (k), value(v)   {

    }
    /// CTOR with a key AND a value: pushes the value into the value_list
    friend ostream& operator << ( ostream& outs, const Pair<K, V>& p )
    {
        outs << std::left << setw(15) << p.key  << "\t" << setw( 5 )
             << "|" << right <<  p.value ;
        return outs;
    }

    friend bool operator == (const Pair<K, V>& lhs, const Pair<K,V>& rhs)
    {
        return ( lhs.key == rhs.key);
    }

    friend bool operator < (const Pair<K, V>& lhs, const Pair<K,V>& rhs)
    {
        return ( lhs.key < rhs.key);
    }

    friend bool operator > (const Pair<K, V>& lhs, const Pair<K,V>& rhs)
    {
        return ( lhs.key > rhs.key);
    }

    friend bool operator <= (const Pair<K, V>& lhs, const Pair<K,V>& rhs)
    {
        return ( lhs.key <= rhs.key);
    }

    friend bool operator >= (const Pair<K, V>& lhs, const Pair<K,V>& rhs)
    {
        return ( lhs.key >= rhs.key);
    }

    friend Pair<K,V> operator +( const Pair<K,V>& lhs, const Pair<K,V>& rhs)
    {
        assert( lhs.key == rhs.key && "operator +: lhs.key != rhs.key " );
        return ( Pair( lhs.key  , rhs.value ) );
//        return ( Pair( lhs.key  , lhs.value /*+ rhs.value */) );

    }
};


#endif // PAIR_H
