#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include "../../!includes/Heap/heap.h"

using namespace  std;


template <typename T>
struct info
{
    T item;
    int priority;
    int time_stamp;

    info();
    info(T i, int p, int t_s = 0);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const info<U>& print_me);

    template <typename U>
    friend bool operator <(const info<U>& lhs, const info<U>& rhs);

    template <typename U>
    friend bool operator >(const info<U>& lhs, const info<U>& rhs);

};

template <typename T>
info<T>::info()
{
}

template <typename T>
info<T>::info(T i, int p, int t_s): item (i), priority(p),
                time_stamp(t_s)
{
}

template <typename U>
ostream& operator <<(ostream& outs, const info<U>& print_me)
{
    outs << print_me.item  ;
    return outs;
}

template <typename U>
bool operator < (const info<U>& lhs, const info<U>& rhs)
{
    ///if lhs priority is less than rhs' proirity, return true;
    if(lhs.priority < rhs.priority)
        return true;

    ///if lhs priority is greater than rhs' proirity, return false;
    else if(lhs.priority > rhs.priority )
        return false;

    else        ///if both have equal proirity
    {
        /// if lhs has a smaller time stamp, it has high priority
        /// return false;
        if(lhs.time_stamp < rhs.time_stamp)
            return false;

        else if(lhs.time_stamp > rhs.time_stamp)
            return true;

        assert(lhs.time_stamp != rhs.time_stamp &&
                "two time stamps should never be equal");
    }
}

template <typename U>
bool operator >(const info<U>& lhs, const info<U>& rhs)
{
    ///if lhs priority is greater than rhs' proirity, return true;
    if(lhs.priority > rhs.priority)
        return true;

    ///if lhs priority is less than rhs' proirity, return false;
    else if(lhs.priority < rhs.priority )
        return false;

    else        ///if both have equal proirity
    {
        /// if lhs has a smaller time stamp, it has high priority
        /// return true;
        if(lhs.time_stamp < rhs.time_stamp)
            return true;
        else if(lhs.time_stamp > rhs.time_stamp)
            return false;

        assert(lhs.time_stamp != rhs.time_stamp &&
                "two time stamps should never be equal");
    }
}

/// ============== --------------  ============== --------------
///     priority queue using info struct and heap class
/// ============== --------------  ============== --------------


template <typename T>
class PQueue
{
public:
    PQueue();

    bool insert(const T& value, int p);

    bool is_empty() const;

    T Pop();

    void print_tree() const;

    unsigned int size() const;

    template<typename U>
    friend ostream& operator << (ostream& outs, const PQueue<U>& print_me);

private:
    Heap< info<T> > heap;
    int stamp = 0;  // a private variable that gives time for
                    // time_stamp varaible in info struct when dealing
                    // with  duplicates

};

template <typename T>
PQueue<T>::PQueue()
{
    stamp = 0;
}

// ============== ============== ============== ==============

template <typename T>
bool PQueue<T>::insert(const T& value, int p)
{
    cout << "item: " << value << "      priority: " << p <<
            "   t_stamp: " << stamp << endl;

    heap.insert(info<T>(value, p, stamp));
    stamp++;
    return true;
}


template<typename T>
bool PQueue<T>::is_empty() const
{
    return heap.is_empty();
}

template<typename T>
T PQueue<T>::Pop()
{
    const bool DEBUG = true;
    if(size() <= 0)    {
        cout << "PQueue is empty. Noting to pop" << endl ;
        return T();
    }

    info<T> temp = heap.Pop();
    cout << "item: " << temp.item;

    if (DEBUG)
         cout << "    priority: "<< temp.priority << "     t_stamp: "
         << temp.time_stamp;
    cout << endl;

    return temp.item;

}

template<typename T>
void PQueue<T>::print_tree() const
{
    cout << heap ;
}

template<typename T>
unsigned int PQueue<T>::size() const
{
    return heap.size();
}

template<typename U>
ostream& operator << (ostream& outs, const PQueue<U>& print_me)
{
    outs << print_me.heap << endl; ;
    return outs;
}


#endif // PQUEUE_H
