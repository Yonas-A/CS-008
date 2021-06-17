#ifndef MAP_H
#define MAP_H

#include <iostream>

#include "../../!includes/B_Tree/b_tree.h"
#include "../../!includes/Pair/multipair.h"

using namespace std;

/// \note there is no Iterator for Multimap class
///       with BTree private member variable

template < typename K, typename V >
class MMap
{

public:
    typedef BTree < MPair<K, V> > map_base;

    MMap();
    // default ctor


    int count ( const K& key ) ;

    void clear();

    bool contains( const K& key ) const ;

    bool empty() const;

    void erase(const K& key);

    V find(const K& key);

    vector<V>& get( const K& key);

    void insert(const K& k, const V& v);

    bool is_valid( );

    vector<V>& operator[] ( const K& key);

    const vector<V>& operator[]( const K& key) const;

    int size() const;

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me)
    {
        outs << print_me.mmap << endl;
        return outs;
    }

private:

    BTree< MPair<K, V> > mmap;
    int key_count;
};

//================================
//  Default Ctor
//================================

template < typename K, typename V >
MMap<K,V>::MMap(): mmap(), key_count( 0 )
{
}


template < typename K, typename V >
int MMap<K, V>::count( const K& key )
{
    return mmap.get( MPair<K, V> (key) ).value_list.size();
    // returns the value_list count in a given key
    // i.e. size of value_list number count in a key
}

template < typename K, typename V >
void MMap<K,V>::clear( )
{
    mmap.clear_tree();
}

template < typename K, typename V >
bool MMap<K,V>::contains( const K& key ) const
{
    return mmap.contains( MPair<K, V> ( key ) );
}


template < typename K, typename V >
bool MMap<K,V>::empty( ) const
{
    return mmap.empty( );
}


template < typename K, typename V >
void MMap<K,V>::erase( const K& target )
{
    mmap.remove( MPair<K,V> ( target ) );
}

template < typename K, typename V >
V MMap<K, V>::find( const K& key )
{
    return Iterator ( mmap.find( key ) );
}

template < typename K, typename V >
vector<V>& MMap<K, V>::get( const K& key )
{
    return MMap<K, V>::mmap.get(MPair<K, V> (key) ).value_list;
}

template < typename K, typename V >
void MMap<K,V>::insert( const K& k, const V& v)
{
    mmap.insert( MPair<K,V> (k, v));
    key_count++;
}

template < typename K, typename V >
bool MMap<K,V>::is_valid()
{
    return mmap.is_valid();
}

template < typename K, typename V >
vector<V>& MMap<K,V>::operator[] (const K& key )
{
    return mmap.get( MPair<K, V> ( key ) ).value_list;
}

template < typename K, typename V >
const vector<V>& MMap<K, V>::operator[]( const K& key ) const
{
    return mmap.get( MPair<K, V> ( key ) ).value_list;
}

template < typename K, typename V >
int MMap<K,V>::size( ) const
{
    return mmap.size( );
}


#endif // MAP_H
