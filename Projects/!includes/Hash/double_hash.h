#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace  std;


template <typename T>
class double_hash
{
public:

    static const std::size_t CAPACITY = 811;

    double_hash( );

    bool find(int key, T& result) const;
    
    void insert(const T& entry);
    
    bool is_present(int key) const;

    bool remove(int key);

    std::size_t size( ) const;

    template <typename U>
    friend ostream& operator <<(ostream& outs,const double_hash<U>& ME );

    void print_interactive( ) const;

private:

    static const int NEVER_USED = -1;

    static const int PREVIOUSLY_USED = -2;

    T _data[CAPACITY];

    std::size_t used;

    bool find_index(int key, std::size_t& index) const;
    /// key at index is check

    std::size_t hash(int key) const;
    /// key is given an index

    std::size_t hash2(int key) const;

    void initialize();
    /// initializes the table to NEVER_USED

    bool is_vacant(std::size_t index) const;
    /// checks if table at index is available

    bool never_used(std::size_t index) const;

    std::size_t next_index(std::size_t index, int key) const;

};

///========================================================
///	DOUBLE HASH functions definitions
///========================================================

template <typename T>
double_hash<T>::double_hash( )
{
    used = 0;
    initialize();
}

template <typename T>
bool double_hash<T>::find(int key, T& result) const
{
    std::size_t index;

    assert( key >= 0 && "find( ), key >= 0" );

    bool found = find_index( key, index);
    if ( found )
        result = _data[index];
    return found;
}

template <typename T>
void double_hash<T>::insert(const T& entry)
{
    assert( entry._key >= 0 && "insert( ), _key >= 0");

    /// _data[index] is location for the new entry
    std::size_t index;

    /// Set index so that _data[index] is the spot to place the new entry.
    bool already_present = find_index(entry._key, index);

    /// If the key not found, then find the location for the new entry.
    if (!already_present)
    {
        assert( size( ) < CAPACITY && "insert( ), size < CAPACITY");
        index = hash( entry._key );
        while ( ! is_vacant( index ) )
        {
            index = next_index( index, entry._key );
        }
        ++used;
    }

    _data[index] = entry;
}

template <typename T>
bool double_hash<T>::is_present(int key) const
{
    assert( key >= 0 && "is_present( ), key >= 0" );

    std::size_t index;
    return find_index( key, index );
}

template <typename T>
bool double_hash<T>::remove( int key )
{
    assert( key >= 0 && "remove(), key >= 0");

    std::size_t index;   /// Spot where _data[index].key == key

    bool found = find_index( key,  index);
    if ( found )
    {
        _data[index]._key = PREVIOUSLY_USED;
        /// remove the record and reduce used by 1.
        --used;
    }

    return found;
}

template <typename T>
inline std::size_t double_hash<T>::size( ) const
{
    return used;
}

template<typename U>
std::ostream& operator <<(ostream& outs, const double_hash<U>& me )
{
    for( size_t i = 0; i < me.CAPACITY; ++i)
    {
        cout << "[" << setw(3) << setfill('0')
             << i << "] " <<  me._data[i] << endl;
    }
    return outs;
}

template <typename T>
void double_hash<T>::print_interactive( )  const
{
    for( size_t i = 0; i < CAPACITY; ++i)
    {
        cout << "[" << setw(3) << setfill('0')<< i << "] ";

        if( _data[i]._key == -1)
            cout << " " << endl;
        else if( _data[i]._key == -2)
            cout << "- - - - - -" << endl;
        else
        {
            cout <<  _data[i] << "(" << setw(3) << setfill('0')
                 << hash(_data[i]._key) << ")";

            if( hash(_data[i]._key) != i)
            {
                cout << " *" ;
            }
            cout << endl;
        }
    }
}

/// =======================================================
///   private functions definitions for double hash class
/// =======================================================

template <typename T>
bool double_hash<T>::find_index( int key, std::size_t& i ) const
{
    std::size_t count = 0;
    /// Number of entries that have been examined

    i = hash( key );
    while(( count < CAPACITY ) &&
          ( _data[i]._key != NEVER_USED ) && ( _data[i]._key != key ))
    {
        ++count;
        i = next_index(i, key);
    }
    return (_data[i]._key == key);
}

template <typename T>
inline std::size_t double_hash<T>::hash(int key) const
{
    return ( key % CAPACITY );
}

template <typename T>
inline std::size_t double_hash<T>::hash2(int key) const
{
    return ( 1 + ( key % ( CAPACITY - 2 ) ) );
}

template <typename T>
void double_hash<T>::initialize()
{
    for( size_t i = 0; i < CAPACITY; i++)
    {
        _data[i] = NEVER_USED;
    }
}

template <typename T>
inline bool double_hash<T>::is_vacant(std::size_t index) const
{
    return ( _data[index]._key == NEVER_USED )
            || ( _data[index]._key == PREVIOUSLY_USED );
}

template <typename T>
inline bool double_hash<T>::never_used(std::size_t index) const
{
    assert( index >= 0 && "never_used( ), index >= 0" );

    return ( _data[index]._key == NEVER_USED );
}

template <typename T>
inline size_t double_hash<T>::next_index(size_t index, int key) const
{
    assert( index >= 0 && "next_index( ), index >= 0" );

    return  ( index + hash2(key) ) % CAPACITY;
}

#endif // DOUBLE_HASH_H
