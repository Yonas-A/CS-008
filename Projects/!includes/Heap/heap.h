#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <assert.h>
#include <iomanip>

using namespace  std;

template <typename T>
class Heap
{

public:

/// ======================== CTOR'S ========================
    Heap();
    Heap(unsigned int capacity);

/// ======================== BIG 3 ========================
    Heap(const Heap& other); //copy CTOR

    Heap& operator =(const Heap& rhs);

    ~Heap(); //destructor

/// ==================== main functions ====================

    unsigned int capacity() const;      // returns capacity of heap

    void clear();                       // sets _size to zero

    void copy( T *dest, T* src, int many_to_copy);

    void insert(const T& insert_me);    //insert item into the heap

    bool is_empty() const;              // checks if heap is empty

    T Pop();                            // remove the root from the heap

    unsigned int size() const;          // returns the size of heap

/// extraction operator
    template <typename U>
    friend ostream& operator << (ostream& outs, const Heap<U>& print_me);

private:

/// ============== private utility functions ==============

    void allocate();    /// allocates an array with bigger capacity

    unsigned int big_child_index(unsigned int i) const;

    bool is_leaf(unsigned int i) const;
    // retuns if i has any children at all

    unsigned int left_child_index(unsigned int i)const;
    // returns i's left child location ( index )

    unsigned int right_child_index(unsigned int i) const;
    // returns i's right child location ( index )

    unsigned int parent_index(unsigned int i) const;
    // returns i's parent location ( index )

    void print_tree(ostream& outs = cout) const;

    void print_tree( unsigned int root, int level = 0,
                     ostream& outs = cout) const;

    void swap_with_parent(unsigned int i);
    /// swaps the child of i with its parent

// private memebers of heap class
    unsigned int _capacity; // actual capacity of array
    T* _heap = nullptr;     // a pointer to the dynamic array
    unsigned int _size;     // actual size of entries in the array

};

///===================== DEFAULT CTOR'S =======================

template <typename T>
Heap<T>::Heap():_capacity (10), _heap(nullptr), _size(0)
{
    _heap = new T[_capacity];
}

template <typename T>
Heap<T>::Heap(unsigned int cap ): _capacity(cap), _heap(nullptr),
                                  _size(0)
{
    assert(cap > 0 && "capacity is zero");
    _heap = new T[ _capacity ];
}

///===================== BIG THREE  =======================

template <typename T>
Heap<T>::Heap(const Heap& other)
{
    const bool DEBUG = false;
    if(DEBUG)
        cout << "Heap() COPY CTOR"<< endl;

    _size  = other._size;
    _capacity = other._capacity;

    _heap = new  T [  _capacity ];

    copy(_heap, other._heap, _size);
}

template <typename T>
Heap<T>& Heap<T>::operator =(const Heap& rhs)
{
    const bool DEBUG = false;
    if(DEBUG)
        cout << "Heap:: = ( )" << endl;

    if(this == &rhs)
        return *this;

    if (_heap != nullptr)
        delete[] _heap;

    _size  = rhs._size;
    _capacity = rhs._capacity;

    _heap = new  T [_capacity ];

    copy( _heap, rhs._heap, _size);

    return *this;
}

template <typename T>
Heap<T>::~Heap()//destructor
{
    const bool DEBUG = false;
    if(DEBUG)
        cout << "~Heap() destructor" << endl;

    delete [] _heap;
    _heap = nullptr;
}

/// ========================================================
///                  public functions
/// ========================================================

template <typename T>
unsigned int Heap<T>::capacity() const
{
    return _capacity;
}

template<typename T>
void Heap<T>::clear()
{
    _size = 0;
}

template <typename T>
void Heap<T>::copy(T *dest, T* src, int copy_size)
{
    for ( int i = 0 ; i < copy_size ; i++ )
    {
        *dest = *src;
        dest++;
        src++;
    }
}

template <typename T>
void Heap<T>::insert(const T& insert_me)
{
    const bool DEBUG = false;
    if( size() >= capacity() )
    {
        if(DEBUG)
            cout << "allocating new capacity for: " << insert_me << endl;
        allocate();
    }

    _heap[ size() ] = insert_me;
    //insert item at the left most location in the deepest level
    _size++;

    unsigned int child = size() - 1;   // index of inserted item
    unsigned int parent ;              // parent index of inserted item

    while( child > 0 && _heap[ parent_index( child) ] < _heap[ child ] )
    {
        parent = parent_index( child);
        // if the parent is smaller than the child, swap them
        // until child is no longer larger than parent
        if( DEBUG )
        {
            cout  << "new entry index: " << child << "   new entry: "
                  << _heap[child] << "   parent index: " << parent
                  << "   parent: " << _heap [parent] << endl;
        }

        swap_with_parent(child);    // swap new entry with its parents
        child = parent;
    }

}

template <typename T>
bool Heap<T>::is_empty() const
{
    return size() == 0;
}

template <typename T>
T Heap<T>::Pop()
{
    const bool DEBUG = false;

    if( size() <= 0 )   // if size is zero or less there's noting to erase
        return T();

    T erased = _heap[0];
    _size--;
    _heap[ 0 ] = _heap[ size() ];

    unsigned int parent = 0;    // index for parent
    unsigned int child;

    while( parent < size() && !is_leaf(parent) &&
           _heap [ parent ] < _heap [ big_child_index( parent )] )
    {
        child = big_child_index(parent);

        if(DEBUG)
        {
            cout  << "parent index: " << parent << " parent: "
                  << _heap[ parent ]  << "   child index: " << child
                  << "   child: " << _heap [ child ] << endl;
        }

        swap_with_parent( child );  //swap the child with the parent
        parent = child; // child's index becomes parent's index
    }

    return erased;
}

template <typename T>
unsigned int Heap<T>::size() const
{
    return _size;
}

/// ============== =============== =========== =============
///                  extraction operator
/// ============== =============== =========== =============

template <typename U>
ostream& operator << (ostream& outs, const Heap<U>& print_me)
{
    print_me.print_tree( 0 );
    return outs;
}

/// ============== =============== =========== =============
///        private utility functions defintion
/// ============== =============== =========== =============

template <typename T>
void Heap<T>::allocate()
{
    // allocating bigger capacity for array
    // and copy old value into new array

    _capacity = size() * 2;

    T* temp = _heap;

    _heap = new T [capacity() ];

    copy( _heap, temp, size() );

    delete [] temp; //de-allocating the old heap array
}

template <typename T>
unsigned int Heap<T>::big_child_index ( unsigned int i ) const
{
    unsigned int left = left_child_index(i);
    unsigned int right = right_child_index(i);

    if( right >= size() )
    {
        return left;
    }

    if( _heap[ left ] > _heap[ right ])
    {
        return left;
    }
    else
        return right;
}

template <typename T>
bool Heap<T>::is_leaf ( unsigned int i) const
{
    /// root is leaf if it doesn't have right and left child
    unsigned int left = left_child_index(i);
    unsigned int right = right_child_index(i);

     return ( left >= size() && right >= size());
}

template <typename T>
unsigned int Heap<T>::left_child_index ( unsigned int i ) const
{
    return ( 2 * i + 1 );
}

template <typename T>
unsigned int Heap<T>::right_child_index ( unsigned int i ) const
{
    return ( 2 * i + 2 );
}

template <typename T>
unsigned int Heap<T>::parent_index ( unsigned int i ) const
{
    assert( i != 0 && "parent index() cannot take i as 0" );
    return ( i - 1 ) / 2;
}

template <typename T>
void Heap<T>::print_tree(ostream& outs ) const
{
    outs << "printing heap " << endl;
    for(unsigned int i = 0; i < size(); i++)
    {
        outs << _heap[i] << " ";
    }
    outs << endl;
}

template <typename T>
void Heap<T>::print_tree(unsigned int root, int level,
                         ostream& outs ) const
{
    if ( root < size() )
    {
        print_tree( right_child_index( root ), level + 1 );
        outs << setw(4 * level) << "" << "[" <<  _heap[root]
             << "]" << endl;
        print_tree( left_child_index ( root ), level + 1 );
    }
}

template <typename T>
void Heap<T>::swap_with_parent ( unsigned int i)
{
    T hold = _heap[ parent_index(i)];
    _heap[ parent_index(i)] = _heap[i];
    _heap[i] = hold;
}

#endif // HEAP_H


