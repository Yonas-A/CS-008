#ifndef MAP_H
#define MAP_H

#include <iostream>

#include "../../!includes/BPlus_Tree/bplus_tree.h"
#include "../../!includes/Pair/pair.h"

using namespace std;

template < typename K, typename V >
class Map
{

public:
    typedef BPlusTree < Pair<K, V> > map_base;

    class Iterator
    {
    public:

        friend class Map;

        Iterator( typename map_base::Iterator it = NULL ) : _it( it )
        {

        }

        /// Postfix ++ advance the iterator to the next slot
        Iterator operator ++( int )
        {
            Iterator hold = _it;
            _it++;
            return hold;
        }
        /// Prefix operator
        Iterator operator ++( )
        {
            _it++;
            return *this ;
        }

        Pair<K, V> operator *( )
        {
            return *_it;
        }

        friend ostream& operator << (ostream& outs , const Iterator& it)
        {
            outs <<  &it._it ;
            return outs;
        }

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs)
        {
            return ( lhs._it == rhs._it) ;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs)
        {
            return ( lhs._it != rhs._it) ;
        }

    private:
        typename map_base::Iterator _it;

    };

    Map();

    // ==============================================================
    // iterators

    /// @returns the an iterator to the first element if map is
    ///         not empty or
    /// @returns a null iterator if map is empty
    Iterator begin( ) const ;

    /// @returns an iterator to the end of mmap ( a null iterator)
    Iterator end( ) const ;

    /// @returns Mpair of iterators of lowerbound & upperbound of key
    Pair< Iterator,Iterator > equal_range( const K& key ) const ;
    /// returns the bounds of a range that includes all the elements
    ///  in the map which have a key equivalent to k.

    /// @returns an iterator to key if key exists the in multimap OR
    /// @returns an iterator to the first element which is not less
    ///          than key if key does not exist
    Iterator lower_bound( const K& key ) const ;
    /// \note return value could also be null if key is the greatest
    ///       element in multimap or multimap is empty

    /// @returns an iterator  to the first element which is greater
    ///          than key
    Iterator upper_bound( const K& key ) const ;
    /// \note return value can be a Null iterator if key is the
    ///        greates element in Multimap, or if Multimap is empty


    // ==============================================================
    // element accessors

    /// @returns a reference to the this key if key already exists
    ///         or if key does not exist,
    /// it inserts key into the multimap and @returns a reference
    ///  to the value of this newly inserted item
    V& at( const K& key );


    /// @returns a const reference to the this key if key already
    ///          exists  or
    /// asserts if key does not exist,
    const V& at( const K& key ) const;


    /// @returns a reference to the this key if key already exists
    ///         or if key does not exist,
    /// it inserts key into the multimap and @returns a reference
    ///  to the value of this newly inserted item
    V& operator[]( const K& key );

    /// @returns a const reference to the this key if key already
    ///          exists  or
    /// asserts if key does not exist,
    const V& operator[]( const K& key ) const;

    // ==============================================================
    // modifiers

    /// clear everything in this object
    void clear( );

    /// removes key from mmap if key exists in the multimap or
    /// does nothing
    void erase( const K& key );

    /// @returns a reference to the this key if key already exists
    ///         or if key does not exist,
    /// it inserts key into the multimap and @returns a reference
    ///  to the value of this newly inserted item
    V get( const K& key);

    /// insert this Pair( K , V ) into this object
    void insert( const K& k, const V& v );

    // ==============================================================
    // operations

    /// \returns true if map contains target or
    /// \returns false if target does not exist anywhere in the map
    bool contains( const Pair<K, V>& target ) const;

    /// @returns an iterator to this key if key exists in the map or
    /// @returns a null iterator
    Iterator find( const K& key );

    // ==============================================================
    // capacity and size

    /// @returns the total items key is mapped  to if key exists, or
    /// @returns 0
    int count( const K& key ) const;

    /// @returns true if there are no items in this mmap or
    /// @returns false there are any items in this mmap
    bool empty( ) const;

    /// @returns the size of the map if map is not empty or
    /// \returns 0 if mmap is empty
    int size( ) const;

    // ==============================================================
    // validations

    /// @returns true if mmap satisfies its underlining structur's
    ///          rules ( i.e. B+ trees rules )  or
    /// @returns false if mmap doesn't satisfies at least a single
    ///          rule of its underlining structure ( i.e B+ tree )
    bool is_valid( ) const;

    // ==============================================================
    // insertion operator and outputs

    /// prints print_me's keys and value onto the screen
    void print_map_tree( );

    friend ostream& operator<<( ostream& outs, const Map<K,V>& print_me)
    {
        if ( print_me.key_count > 0 )
        {
            Map<K, V >::Iterator it;
            for ( it = print_me.begin( ) ; it != print_me.end( ); ++it )
                outs << *it << endl;
        }

        return outs;
    }

private:
    BPlusTree< Pair<K, V> > map;
    int key_count;
};

//==============================================================
//  Default Ctor
//==============================================================

template < typename K, typename V >
Map<K,V>::Map( ): map( true ), key_count( 0 )
{

}

//==============================================================

template < typename K, typename V >
typename Map<K,V>::Iterator Map<K,V>::begin( ) const
{
    return ( map.begin() );
}

template < typename K, typename V >
typename Map<K,V>::Iterator Map<K,V>::end( ) const
{
    return ( map.end() );
}

template <typename K, typename V >
Pair<typename Map<K,V>::Iterator,typename Map<K,V>::Iterator>
                    Map<K,V>::equal_range( const K& key ) const
{
    return ( Pair<Iterator,Iterator> (lower_bound(key ) , upper_bound(key) ));
    /// \returns the a pair of iterators to the lower bound
    ///          and upperbound of the key
}

template < typename K, typename V >
typename Map<K,V>::Iterator Map<K,V>::lower_bound( const K& key ) const
{
    /// call B+ tree's lower bound on this key
    /// and \return its return value
    return ( map.lower_bound( key ) );
}

template < typename K, typename V >
typename Map<K,V>::Iterator Map<K,V>::upper_bound(const K& key ) const
{
    /// call B+ tree's upper bound on this key
    /// and \return its return value
    return ( map.upper_bound( key ) );
}

//==============================================================
// element accessors

template < typename K, typename V >
V& Map<K,V>::at( const K& key )
{
    if ( find( key ) == Iterator( nullptr ) )    {
        key_count++;
        /// if key is not already in the tree add one to key_count
    }

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
    if ( find( key ) == Iterator( nullptr ) )    {
        key_count++;
        /// if key is not already in the tree add one to key_count
    }

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
    /// clear map and set the key count to zero
    map.clear();
    key_count = 0;
}

template < typename K, typename V >
void Map<K,V>::erase(const K& target )
{
    if ( find( target ) != Iterator( nullptr ))
    {
        map.remove( target );
        /// if target is in the tree remove it and reduce key_count by one
        key_count--;
    }

}

template < typename K, typename V >
V Map<K,V>::get ( const K& key )
{
    if ( find( key ) == Iterator( nullptr ))     {
        key_count++;
        /// if key is not already in the map add one to key_count
    }

    return map.get( key ).value;
}

template < typename K, typename V >
void Map<K,V>::insert( const K& k, const V& v)
{
    if ( find( k ) == Iterator( nullptr ))     {
        key_count++;
        /// if key is not already in the map add one to key_count
    }

    map.insert( Pair<K,V> (k, v )) ;
}

//==============================================================

template < typename K, typename V >
bool Map<K,V>::contains(const Pair<K,V>& target ) const
{
    return map.contains(target);
}

template < typename K, typename V >
typename Map<K,V>::Iterator Map<K,V>::find( const K& key )
{
    return Iterator ( map.find( key ) );
}
//==============================================================

template < typename K, typename V >
int Map<K, V>::count( const K& key ) const
{
    /// \if
    if ( map.find ( key ) != Iterator( nullptr) )
        return 1;
    else
        return 0;

//    return map.get( Pair<K, V> ( key ) ).value.size();
    /// \returns size of value_list, total no of items in a key
}

template < typename K, typename V >
bool Map<K,V>::empty( ) const
{
    return map.empty();
}

template < typename K, typename V >
int Map<K,V>::size ( ) const
{
    if ( const bool DEBUG = true )
        cout << "Map::size ( ) key count: " << key_count<< "    ";
    return map.size( );
}

//==============================================================

template < typename K, typename V >
bool Map<K,V>::is_valid() const
{
    return map.is_valid();
}

//==============================================================

template < typename K, typename V >
void Map<K,V>::print_map_tree()
{
    cout << map << endl;
}

//==============================================================

#endif // MAP_H
