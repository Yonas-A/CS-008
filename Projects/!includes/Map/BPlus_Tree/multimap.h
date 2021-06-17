#ifndef MMAP_H
#define MMAP_H

#include <iostream>

#include "../../../!includes/BPlus_Tree/bplus_tree.h"
#include "../../../!includes/Pair/multipair.h"

using namespace std;

template < typename K, typename V >
class MMap
{

public:
    typedef BPlusTree < MPair<K, V> > map_base;

    class Iterator
    {
    public:

        friend class MMap;

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

        /// Prefix ++ advance the iterator to the next slot
        Iterator operator ++( )
        {
            _it++;
            return *this;
        }

        MPair<K, V> operator *( )
        {
            return *_it;
        }

        friend bool operator == (const Iterator& lhs, const Iterator& rhs)
        {
            return ( lhs._it == rhs._it ) ;
        }

        friend bool operator != (const Iterator& lhs, const Iterator& rhs)
        {
            return ( lhs._it != rhs._it ) ;
        }

    private:
        typename map_base::Iterator _it;

    };

    MMap( );

    // ==============================================================
    // iterators

    /// @returns the an iterator to the first element if map is
    ///         not empty or
    /// @returns a null iterator if map is empty
    Iterator begin( ) const ;

    /// @returns an iterator to the end of mmap ( a null iterator)
    Iterator end( ) const;

    /// @returns Mpair of iterators of lowerbound & upperbound of key
    MPair<Iterator,Iterator> equal_range( const K& key ) const ;
    /// \returns the bounds of a range that includes all the elements
    ///  in the multimap which have a key equivalent to k.

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
    vector<V>& operator[] ( const K& key);


    /// @returns a const reference to the this key if key already
    ///          exists  or
    /// asserts if key does not exist,
    const vector<V>& operator[]( const K& key) const;

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
    vector<V>& get( const K& key );


    /// insert this MPair( K , V ) into this object
    void insert( const K& k, const V& v );

    // ==============================================================
    // operations

    /// @returns true if key is found in mmap or
    /// @returns false if key cannot be not found in this mmap
    bool contains( const K& key ) const ;

    /// @returns an iterator to this key if key exists in the mmap or
    /// @returns a null iterator
    Iterator find( const K& key );


    // ==============================================================
    // capacity and size


    /// @returns the total items key is mapped  to if key exists, or
    /// @returns 0
    int count ( const K& key ) ;
    /// returns the size of the vector key k is associated with

    /// @returns true if there are no items in this mmap or
    /// @returns false there are any items in this mmap
    bool empty( ) const;


    /// @returns the size of the map if map is not empty or
    /// \returns 0 if mmap is empty
    int size( ) const;
    /// the total size of the underlining B+ tree structure


    // ==============================================================
    // validations

    /// @returns true if mmap satisfies its underlining structur's
    ///          rules ( i.e. B+ trees rules )  or
    /// @returns false if mmap doesn't satisfies at least a single
    ///          rule of its underlining structure ( i.e B+ tree )
    bool is_valid( );


    // ==============================================================

    /// prints print_me's keys and value_list vectors onto the screen
    void print_mmap_tree( );

    friend ostream& operator <<( ostream& outs, const MMap<K, V>& print_me)
    {
        if ( print_me.key_count > 0 )
        {
            MMap<K, V >::Iterator it;
            for ( it = print_me.begin( ) ; it != print_me.end( ); ++it )
                outs << *it << endl;
        }
        return outs;
    }

private:

    BPlusTree< MPair<K, V> > mmap;
    int key_count;
};

//==============================================================
//  Default Ctor

template < typename K, typename V >
MMap<K,V>::MMap( ): mmap( ), key_count( 0 )
{

}

//==============================================================
// iterators
template < typename K, typename V >
typename MMap<K,V>::Iterator MMap<K,V>:: begin( ) const
{
    return ( mmap.begin() );
}

template < typename K, typename V >
typename MMap<K,V>::Iterator MMap<K,V>:: end( ) const
{
    return ( mmap.end() );
}

template <typename K, typename V>

MPair<typename MMap<K,V>::Iterator,typename MMap<K,V>::Iterator>
                MMap<K,V>::equal_range(const K& key) const
{
    return (MPair<Iterator,Iterator>(lower_bound(key ), upper_bound(key)));

    /// \returns the a MPair of iterators to the lower bound
    ///          and upperbound of the key
}

template < typename K, typename V >
typename MMap<K,V>::Iterator MMap<K,V>::lower_bound( const K& key ) const
{
    /// call B+ tree's lower bound on this key
    /// and \return its return value
    return ( mmap.lower_bound( key ) );

}

template < typename K, typename V >
typename MMap<K,V>::Iterator MMap<K,V>::upper_bound(const K& key ) const
{
    /// call B+ tree's upper bound on this key
    /// and \return its return value
    return ( mmap.upper_bound( key ) );
}

//==============================================================
// element accessors

template < typename K, typename V >
vector<V>& MMap<K,V>::operator[] ( const K& key )
{
    if ( find( key ) == Iterator( nullptr ))    {
        key_count++;
        /// if key is not already in the tree add one to key_count
    }

    return mmap.get( MPair<K, V> ( key ) ).value_list;
}

template < typename K, typename V >
const vector<V>& MMap<K, V>::operator[]( const K& key ) const
{
    return mmap.get( MPair<K, V> ( key ) ).value_list;
}

//==============================================================
// modifiers

template < typename K, typename V >
void MMap<K,V>::clear( )
{
    /// clear mmap and set the key count to zero
    mmap.clear();
    key_count = 0;
}

template < typename K, typename V >
void MMap<K,V>::erase( const K& target )
{
    if ( find( target ) != Iterator( nullptr ))
    {
        mmap.remove( target );
        /// if target is in the tree remove it and reduce key_count by one
        key_count--;
    }
}


template < typename K, typename V >
vector<V>& MMap<K, V>::get( const K& key )
{
    if ( find( key ) == Iterator( nullptr ))     {
        key_count++;
        /// if key is not already in the mmap add one to key_count
    }

    return MMap<K, V>::mmap.get(MPair<K, V> (key) ).value_list;
}

template < typename K, typename V >
void MMap<K,V>::insert( const K& k, const V& v)
{
    if ( find( k ) == Iterator( nullptr ))     {
        key_count++;
        /// if key is not already in the mmap add one to key_count
    }

    mmap.insert( MPair<K,V>( k, v ) );
}

//==============================================================
// operations
template < typename K, typename V >
bool MMap<K,V>::contains( const K& key ) const
{
    return mmap.contains( MPair<K, V> ( key ) );
}

template < typename K, typename V >
typename MMap<K,V>::Iterator MMap<K,V>::find( const K& key )
{
    return Iterator ( mmap.find( key ) );
}

//==============================================================
// capacity

template < typename K, typename V >
int MMap<K, V>::count( const K& key ) /*const*/
{
    if ( mmap.contains( key ) )
    {
        return mmap.get(  key  ).value_list.size();
    }

    /// \returns size of value_list, total no of items in a key
    else
        return 0;
}

template < typename K, typename V >
bool MMap<K,V>::empty( ) const
{
    return mmap.empty( );
}

template < typename K, typename V >
int MMap<K,V>::size( ) const
{
    if ( const bool DEBUG = true )
        cout << "MMap::size ( ) key count: " << key_count << endl;
    return mmap.size( );
}

//==============================================================
// validation

template < typename K, typename V >
bool MMap<K,V>::is_valid()
{
    return mmap.is_valid();
}

//==============================================================

template < typename K, typename V >
void MMap<K,V>::print_mmap_tree()
{
    cout << mmap << endl;
}

//==============================================================


#endif // MMAP_H
