#ifndef AVL_H
#define AVL_H
#include <iostream>

#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"

using namespace std;

template <typename T>
class avl {
   public:
    avl();
    avl(const T* sorted_list, int size = -1);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    avl(const avl<T>& copy_me);
    avl<T>& operator=(const avl<T>& rhs);
    ~avl();

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void clear();
    void erase(const T& target);
    void insert(const T& insert_me);
    void print_inorder();
    bool search(const T& target, tree_node<T>*& found_ptr);

    friend ostream& operator<<(ostream& outs, const avl<T>& tree) {
        tree_print(tree.root, 0, outs);
        // tree_print_debug(tree.root, 0, outs);
        return outs;
    }

    avl<T>& operator+=(const avl<T>& rhs);

   private:
    tree_node<T>* root;
};

//==============================================================
//  CONSTRUCTORS
//==============================================================
template <typename T>
avl<T>::avl() : root(nullptr) {
}

template <typename T>
avl<T>::avl(const T* sorted_list, int size) {
    root = tree_from_sorted_list(sorted_list, size);
}

//==============================================================
//        Big Three functions
//==============================================================

template <typename T>
avl<T>::avl(const avl<T>& copy_me) {
    const bool DEBUG = false;
    if (DEBUG) {
        cout << "avl () COPY CTOR" << endl;
    }

    root = tree_copy(copy_me.root);
}

template <typename T>
avl<T>& avl<T>::operator=(const avl<T>& rhs) {
    const bool DEBUG = false;
    if (DEBUG) {
        cout << "avl:: = ( )" << endl;
    }

    if (this == &rhs)
        return *this;

    if (root != nullptr) {
        tree_clear(root);  // clearing the avl
        root = NULL;
    }

    root = tree_copy(rhs.root);  // copying the rhs to the avl

    return *this;
}

template <typename T>
avl<T>::~avl() {
    const bool DEBUG = false;
    if (DEBUG) {
        cout << "~avl" << endl;
    }

    tree_clear(root);
    root = NULL;
}
//==============================================================
//
//==============================================================

template <typename T>
void avl<T>::clear() {
    tree_clear(root);
    root = NULL;
}

template <typename T>
void avl<T>::erase(const T& target) {
    bool DEBUG = false;
    bool erased = tree_erase(root, target);

    if (DEBUG) {
        if (erased) {
            cout << "target erased: " << endl;
        } else
            cout << "target not found" << endl;
    }
}

template <typename T>
void avl<T>::insert(const T& insert_me) {
    tree_insert<T>(root, insert_me);
}

template <typename T>
void avl<T>::print_inorder() {
    tree_print_inorder(root);
}

template <typename T>
bool avl<T>::search(const T& target, tree_node<T>*& found_ptr) {
    return tree_search(root, target, found_ptr);
}

template <typename T>
avl<T>& avl<T>::operator+=(const avl<T>& RHS) {
    tree_add(root, RHS.root);
    return *this;
}

#endif  // AVL_H
