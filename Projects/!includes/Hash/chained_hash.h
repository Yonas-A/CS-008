#ifndef CHAIN_HASH_H
#define CHAIN_HASH_H

#include <cstdlib>  // Provides size_t
#include <iomanip>
#include <iostream>

#include "../../!includes/AVL/avl.h"
#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"

using namespace std;

template <typename T>
class chained_hash {
   public:
    static const std::size_t TABLE_SIZE = 11;

    chained_hash();  /// default ctor

    chained_hash(const chained_hash<T>& other);

    chained_hash<T>& operator=(const chained_hash<T>& rhs);

    ~chained_hash<T>();

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool find(int key, T& result) const;

    void insert(const T& entry);

    bool is_present(int key) const;

    bool remove(int key);

    std::size_t size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& outs,
                                    const chained_hash<U>& print_me);

    void print_interactive();

   private:
    avl<T>* _data = nullptr;
    std::size_t total_records;

    tree_node<T>* find_ptr(int key) const;

    std::size_t hash(int key) const;
};

///. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
chained_hash<T>::chained_hash() {
    _data = new avl<T>[TABLE_SIZE];
    /// _data points to 11 avl trees
    total_records = 0;
}
///. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <typename T>
chained_hash<T>::chained_hash(const chained_hash<T>& other) {
    const bool DEBUG = false;
    if (DEBUG) {
        cout << "chained_hash () COPY CTOR" << endl;
    }

    _data = new avl<T>[TABLE_SIZE];

    for (size_t i = 0; i < other.TABLE_SIZE; i++) {
        _data[i] = other._data[i];
    }

    total_records = other.total_records;
}

template <typename T>
chained_hash<T>& chained_hash<T>::operator=(const chained_hash<T>& rhs) {
    const bool DEBUG = false;
    if (DEBUG) {
        cout << "chained_hash:: = ( )" << endl;
    }

    if (this == &rhs)
        return *this;

    if (_data != nullptr)
        delete[] _data;

    _data = new avl<T>[TABLE_SIZE];

    for (size_t i = 0; i < rhs.TABLE_SIZE; i++) {
        _data[i] = rhs._data[i];
    }
    total_records = rhs.total_records;

    return *this;
}

template <typename T>
chained_hash<T>::~chained_hash<T>() {
    const bool DEBUG = false;
    if (DEBUG) {
        cout << "~chained_hash" << endl;
    }

    delete[] _data;
}

///. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
bool chained_hash<T>::find(int key, T& result) const {
    assert(key >= 0 && "find( ), _key >= 0");

    tree_node<T>* already_present = nullptr;
    already_present = find_ptr(key);
    /// if key is found already_present points at node holding key
    if (already_present != nullptr) {
        result = already_present->_item;
        /// set result to the item already_present points at
        return true;
        /// return true indicating key was found
    }

    return false;
    /// key was not found, return false
}

template <typename T>
void chained_hash<T>::insert(const T& entry) {
    assert(entry._key >= 0 && "insert( ), _key >= 0");

    tree_node<T>* already_present = nullptr;
    already_present = find_ptr(entry._key);
    /// if key is found already_present points at node holding key
    if (already_present == nullptr) {
        _data[hash(entry._key)].insert(entry);
        /// at the right index of the _data array, insert the
        /// entry at item using insert() from avl
        ++total_records;
        /// increase the total_records in the table by 1
    } else {
        already_present->_item = entry;
        /// update item already_present points at to entry
    }
}

template <typename T>
bool chained_hash<T>::is_present(int key) const {
    assert(key >= 0 && "is_present( ), key >= 0");

    tree_node<T>* found = nullptr;
    /// if key exists, found will point to the key
    return _data[hash(key)].search(key, found);
    /// search() returns true if key was found or false
    /// if key was not found
}

template <typename T>
bool chained_hash<T>::remove(int key) {
    assert(key >= 0 && "remove(), key >= 0");

    ///check if record with key exists
    if (is_present(key)) {
        _data[hash(key)].erase(key);
        /// erase the pointer a
        total_records--;
        /// reduce total records by 1
        return true;
    }

    return false;
    /// key does not exist so return false
}

template <typename T>
inline std::size_t chained_hash<T>::size() const {
    return total_records;
}

template <typename U>
ostream& operator<<(ostream& outs, const chained_hash<U>& hash) {
    for (size_t i = 0; i < hash.TABLE_SIZE; i++) {
        outs << "[" << setw(3) << setfill('0') << i << "] ";
        hash._data[i].print_inorder();
    }
    return outs;
}

template <typename T>
void chained_hash<T>::print_interactive() {
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        cout << "[" << setw(3) << setfill('0') << i << "] ";
        _data[i].print_inorder();
    }
}

/// ==============================================================
///         private function definition
/// ==============================================================

template <typename T>
tree_node<T>* chained_hash<T>::find_ptr(int key) const {
    tree_node<T>* found = nullptr;
    /// a pointer to point at the key if found
    _data[hash(key)].search(key, found);
    /// at the specific array containing key,search for key exists,
    /// and if key exists, point found to the node holding key
    return found;
    /// return the pointer
}

template <typename T>
inline std::size_t chained_hash<T>::hash(int key) const {
    return (key % TABLE_SIZE);
}

#endif  // CHAIN_HASH_H
