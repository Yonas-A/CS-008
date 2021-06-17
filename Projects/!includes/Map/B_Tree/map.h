#ifndef MAP_H
#define MAP_H

#include <iostream>

#include "../../!includes/B_Tree/b_tree.h"
#include "../../!includes/Pair/pair.h"

using namespace std;

template < typename K, typename V >
class Map
{

public:

    Map();

    // ==============================================================
    // element accessors

    V& at( const K& key );
    /// a reference to access item at key

    const V& at( const K& key ) const;
    /// a const reference to access item at key

    V& operator[]( const K& key );
    /// a reference to item at key

    const V& operator[]( const K& key ) const;
    /// a const reference to access item at key

    // ==============================================================
    // modifiers

    void clear( );

    void erase( const K& key );

    V get( const K& key);

    void insert( const K& k, const V& v );

    // ==============================================================
    // operations

    bool contains( const Pair<K, V>& target ) const;

    V find( const K& key ) const;

    // ==============================================================
    // capacity
    bool empty( ) const;

    int size( ) const;

    // ==============================================================
    // validations

    bool is_valid( );

    // ==============================================================


    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me)
    {
        outs<< print_me.map << endl;
        return outs;
    }


private:
    BTree<Pair<K, V> > map;
    int key_count;
};

//==============================================================
//  Default Ctor

template < typename K, typename V >
Map< K,V >::Map( ): map( true ), key_count( 0 )
{

}

//==============================================================

template < typename K, typename V >
V& Map<K,V>::at( const K& key )
{
    return map.get( key ).value;
}

template < typename K, typename V >
const V& Map<K,V>::at( const K& key ) const
{
    return map.get( key ).value;
}

template < typename K, typename V >
V& Map<K,V>::operator [] (const K& key )
{
    return map.get( key ).value;
}

template < typename K, typename V >
const V& Map<K,V>::operator [] (const K& key ) const
{
    return map.get( key ).value;
}

//==============================================================

template < typename K, typename V >
void Map<K,V>::clear( )
{
    map.clear_tree();
}

template < typename K, typename V >
void Map<K,V>::erase( const K& target )
{
    map.remove( target );
}

template < typename K, typename V >
V Map<K,V>::get ( const K& key )
{
    return map.get( key ).value;
}

template < typename K, typename V >
void Map<K,V>::insert( const K& k, const V& v)
{
    map.insert( Pair<K,V> (k, v ));
}

//==============================================================

template < typename K, typename V >
bool Map<K,V>::contains(const Pair<K,V>& target ) const
{
    return map.contains(target);
}

template < typename K, typename V >
V Map<K, V>::find( const K& key ) const
{
    return map.find( key ) ;
}

//==============================================================

template < typename K, typename V >
bool Map<K,V>::is_valid()
{
    return map.is_valid();
}

//==============================================================

template < typename K, typename V >
bool Map<K,V>::empty( ) const
{
    return map.empty();
}

template < typename K, typename V >
int Map<K,V>::size ( ) const
{
    return map.size( );
}

//==============================================================

#endif // MAP_H
