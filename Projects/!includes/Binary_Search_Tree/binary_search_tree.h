#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <array>
#include <iomanip>
#include <iostream>

#include "../../!includes/Binary_Search_Tree/union.h"

using namespace std;

template <typename T>
struct tree_node {
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;

    int balance_factor() {
        int left_height = 0;
        int right_height = 0;

        if (_left == nullptr)
            left_height = -1;
        else
            left_height = _left->_height;

        if (_right == nullptr)
            right_height = -1;
        else
            right_height = _right->_height;

        return (left_height - right_height);

        //        //a NULL child has a height of -1
        //        //a leaf has a height of 0
    }

    int height() {
        int left_height = 0;
        int right_height = 0;

        if (_left == nullptr)
            left_height = -1;
        else
            left_height = _left->_height;

        if (_right == nullptr)
            right_height = -1;
        else
            right_height = _right->_height;

        return 1 + (max(left_height, right_height));
    }

    int update_height() {
        //set the _height member variable ( call height() )
        _height = height();
        return _height;
    }

    tree_node(T item = T(), tree_node* left = NULL,
              tree_node* right = NULL) : _item(item), _left(left), _right(right) {
        _height = height();
    }

    friend ostream& operator<<(ostream& outs,
                               const tree_node<T>& t_node) {
        outs << "|" << t_node._item << "|";
    }
};

///============================================================
///     function declaration for binary search tree
///============================================================

template <typename T>
void tree_add(tree_node<T>*& dest, const tree_node<T>* src);
//Add tree src to dest

template <typename T>
void tree_clear(tree_node<T>*& root);
//clear the tree

template <typename T>
tree_node<T>* tree_copy(tree_node<T>* root);
//return copy of ree pointed to by root

template <typename T>
bool tree_erase(tree_node<T>*& root, const T& target);
//erase target from the tree

template <typename T>
void tree_insert(tree_node<T>*& root, const T& insert_me);

template <typename T>
void tree_print(tree_node<T>* root, int level = 0,
                ostream& outs = cout);

template <typename T>
void tree_print_debug(tree_node<T>* root, int level = 0,
                      ostream& outs = cout);
//prints details info about each node

template <typename T>
void tree_print_inorder(tree_node<T>* root);

template <typename T>
void tree_remove_max(tree_node<T>*& root, T& max_value);
// erase rightmost node from the tree
//  store the item in max_value

///============================================================

template <typename T>
void tree_rotate(tree_node<T>*& root);

template <typename T>
tree_node<T>* rotate_left(tree_node<T>*& root);

template <typename T>
tree_node<T>* rotate_left_right(tree_node<T>*& root);

template <typename T>
tree_node<T>* rotate_right(tree_node<T>*& root);

template <typename T>
tree_node<T>* rotate_right_left(tree_node<T>*& root);

///============================================================

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target);
// search the tree for a target
// a pointer to the node is returned if target if found
// if target is not found, a nullptr is returned

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>*& found_ptr);
// search the tree for a target
// return true if target found, and point found_ptr to target node
// return false if not found, and set found_ptr to nullptr

template <typename T>
int tree_size(const tree_node<T>* root);
// goes through the entire tree and counts the nodes
// returns the number of nodes in the tree

template <typename T>
tree_node<T>* tree_from_sorted_list(const T* ptr, int size);
// from a given array with size, construct a balanced tree
// return the tree

template <typename T>
T* tree_traversal_in_order(const tree_node<T>* root, int& size, T* arr);
// inorder treversal of tree

///============================================================
///============================================================
///      function definitions for binary search tree (BST)
///============================================================
///============================================================

template <typename T>
void tree_add(tree_node<T>*& dest, const tree_node<T>* src) {
    const bool DEBUG = false;

    int src_size = 0, dest_size = 0, union_size = 0;

    /// \note tree_size<T>( test tree ) returns size of the tree
    T* src_arr = new T[tree_size<T>(src)];
    T* dest_arr = new T[tree_size<T>(dest)];

    src_arr = tree_traversal_in_order(src, src_size, src_arr);
    dest_arr = tree_traversal_in_order(dest, dest_size, dest_arr);

    if (DEBUG) {
        cout << "Printing src and dest arrays " << endl;
        print(src_arr, src_size);
        print(dest_arr, dest_size);
    }

    /// clearing the destination tree before making potentially a bigger tree
    tree_clear(dest);

    if (DEBUG) {
        cout << "dest tree cleared successfully" << endl
             << endl;
        tree_print(dest);
    }

    /// getting the union of the two trees
    T* hold = Union(src_arr, src_size, dest_arr, dest_size, union_size);

    if (DEBUG) {
        cout << "union of src and dest successfull. now printing\n";
        print(hold, union_size);
    }

    /// making a tree at dest from the union of two trees
    dest = tree_from_sorted_list(hold, union_size);

    delete[] dest_arr;
    delete[] src_arr;
    delete[] hold;
    /// clearing the spaces from the all arrays used above
}

template <typename T>
void tree_clear(tree_node<T>*& root) {
    /// \note Steps
    ///     if root exists go to the left and right of root and delete
    ///     the root and set each root as null
    if (root) {
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = nullptr;
    }
}

template <typename T>
tree_node<T>* tree_copy(tree_node<T>* root) {
    /// STEPS
    ///     grab the item at root, its left and right roots,
    ///     and make a new tree
    /// \note
    ///     the tree node constructor takes care of the height
    ///     a tree from the height() so the height of the new
    ///     tree is automatically updated accordingly

    if (root) {
        return new tree_node<T>(root->_item,
                                tree_copy(root->_left),
                                tree_copy(root->_right));
    } else
        return nullptr;
}

template <typename T>
bool tree_erase(tree_node<T>*& root, const T& target) {
    /// STEPS
    ///     if root doesn't exist, return false
    ///     else if the target's greater than root's item call erase with
    ///         root's right pointer
    ///     else if the target's less than root's item call erase with
    ///         root's left pointer
    ///     else delete the root
    ///         update height of root  if root is not null after erase
    ///         and also rotate when necessary

    if (root == nullptr)
        return false;

    else if (target < root->_item) {
        /*return*/ tree_erase(root->_left, target);
    }

    else if (target > root->_item) {
        /*return*/ tree_erase(root->_right, target);
    }

    else {
        if (root->_left == nullptr) {
            tree_node<T>* temp = root;
            root = root->_right;
            delete temp;
        }

        else {
            T max_value;
            tree_remove_max(root->_left, max_value);
            root->_item = max_value;
        }
    }

    if (root != nullptr) {
        root->update_height();
        tree_rotate(root);
    }

    return true;
}

template <typename T>
void tree_insert(tree_node<T>*& root, const T& insert_me) {
    /// STEPS
    ///     if root doesn't exist, create a new node with insert me as item
    ///     else if the insert me is greater than root's item call insert with
    ///         root's right pointer
    ///     else if the insert me is less than root's item call erase with
    ///         root's left pointer
    /// \note for this project duplicates are not allowed
    ///         update height of the new root and all the roots
    ///         and also rotate when necessary

    if (root == nullptr) {
        root = new tree_node<T>(insert_me);
    }

    else if (insert_me < root->_item) {
        tree_insert(root->_left, insert_me);
    }

    else if (insert_me > root->_item) {
        tree_insert(root->_right, insert_me);
    }

    root->update_height();
    tree_rotate(root);
}

template <typename T>
void tree_print(tree_node<T>* root, int level, ostream& outs) {
    if (root) {
        tree_print(root->_right, level + 1);
        outs << setw(4 * level) << ""
             << "[" << root->_item
             << "]" << endl;
        tree_print(root->_left, level + 1);
    }
}

template <typename T>
void tree_print_debug(tree_node<T>* root, int level, ostream& outs) {
    /// \note
    /// only used for debugging purpose to see what follows
    ///  and what precedes a root i.e, if it has a left or
    /// right child and what those children are
    if (root) {
        tree_print_debug(root->_right, level + 1);
        outs << setw(4 * level) << ""
             << "[" << root->_item
             << "]" << endl;

        cout << "root h: " << root->_height << endl;
        if (root->_left)
            cout << "L_H: " << root->_left->_height << endl;
        if (root->_right)
            cout << "R_H: " << root->_right->_height << endl;

        tree_print_debug(root->_left, level + 1);
    }
}

template <typename T>
void tree_print_inorder(tree_node<T>* root) {
    /// STEPS
    ///  make an array
    if (root) {
        T arr[tree_size(root)];
        int size = 0;
        tree_traversal_in_order(root, size, arr);
        for (int i = 0; i < size; i++) {
            cout << "[" << arr[i] << "]->";
        }
    }

    cout << "|||" << endl;
}

template <typename T>
void tree_remove_max(tree_node<T>*& root, T& max_value) {
    // if root doesn't have a right, retrieve the value and delete root
    if (root->_right == nullptr) {
        max_value = root->_item;
        tree_node<T>* temp = root;
        root = root->_left;
        delete temp;
    }

    else
        //recursively call root's right until root has no _right
        tree_remove_max(root->_right, max_value);

    if (root != nullptr) {
        root->update_height();
    }
}

//============================================================

template <typename T>
void tree_rotate(tree_node<T>*& root) {
    int balance = root->balance_factor();
    if (balance > 1) {
        if (root->_left->balance_factor() < 0) {
            //      25
            //     /
            //   10
            //    \
            //    12
            rotate_left_right(root);
        } else {
            //         25
            //        /
            //      12
            //     /
            //   10
            rotate_right(root);
        }
    }

    else if (balance < -1) {
        if (root->_right->balance_factor() > 0) {
            //        50
            //         \
            //         70
            //        /
            //       60
            rotate_right_left(root);
        }

        else {
            //      50
            //       \
            //       60
            //        \
            //        70
            rotate_left(root);
        }
    }
}

template <typename T>
tree_node<T>* rotate_left(tree_node<T>*& root) {
    /*  STEPS:
        step 1: hold onto the root's right
        step 2: change root's right to point to hold's left
        step 3: hold's left points at root
            STEP 3.1 UPDATE BOTH HEIGHT OF HOLD AND ROOT HERE
        step 4: root points to hold
   */
    tree_node<T>* hold = root->_right;  // step 1
    root->_right = hold->_left;         // step 2
    hold->_left = root;                 // step 3

    root->update_height();
    hold->update_height();
    root = hold;  // step 4
    return root;
}

template <typename T>
tree_node<T>* rotate_left_right(tree_node<T>*& root) {
    /// \note
    ///     must make sure we pass the root's left when rotating left
    ///     on a root who's left heavy
    ///
    ///     no need to update height since the functions being called
    ///     ( rotate_left() & rotate_right() )take care of height updating

    root->_left = rotate_left(root->_left);
    root = rotate_right(root);
    return root;
}

template <typename T>
tree_node<T>* rotate_right(tree_node<T>*& root) {
    /*  STEPS:
        step 1: hold onto the root's left
        step 2: change root's left to point at hold's right
        step 3: change hold's right to point at root

        STEP 3.1 UPDATE BOTH HEIGHT OF HOLD AND ROOT HERE

        step 4: root points to hold
   */
    tree_node<T>* hold = root->_left;
    root->_left = hold->_right;
    hold->_right = root;

    root->update_height();  // updating the height of root
    hold->update_height();  // updating the small segment of tree (hold)

    root = hold;
    return root;
}

template <typename T>
tree_node<T>* rotate_right_left(tree_node<T>*& root) {
    /// \note
    ///     must make sure we pass the root's left when rotating right
    ///     on a tree with a right heavy root (zigzag tree )
    ///
    ///     no need to update height since the functions being called
    ///     ( rotate_left() & rotate_right() )take care of height updating

    root->_right = rotate_right(root->_right);
    root = rotate_left(root);
    return root;
}

//============================================================

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target) {
    if (root == nullptr)  // tree is empty, return null
        return nullptr;

    else if (root->_item == target)  // if item @ root is target
        return root;

    else if (target < root->_item)  // target is less than item @ root
        return tree_search(root->_left, target);

    else  //if( target > root ->_item) // target is greater than item @ root
        return tree_search(root->_right, target);
}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>*& found) {
    ///\note this function calls the above search function
    found = tree_search(root, target);

    if (found)
        return true;
    else
        return false;
}

template <typename T>
int tree_size(const tree_node<T>* root) {
    if (root == nullptr)
        return 0;

    else
        return (1 + tree_size(root->_left) + tree_size(root->_right));
}

template <typename T>
tree_node<T>* tree_from_sorted_list(const T* a, int size) {
    // continue while this branch has values to process
    if (size <= 0)
        return NULL;

    int mid = size / 2;

    // Get the middle element and make it root
    tree_node<T>* root = new tree_node<T>(a[mid]);

    // construct the left subtree and make it left child of root
    root->_left = tree_from_sorted_list(a, mid);

    // construct the right subtree and make it right child of root
    root->_right = tree_from_sorted_list(a + mid + 1, size - mid - 1);

    return root;
}

template <typename T>
T* tree_traversal_in_order(const tree_node<T>* root, int& size, T* arr) {
    ///\note Steps for inorder traversal
    ///     go to  the left subtree while root has left subtree
    ///                         , i.e., call Inorder(left-subtree)
    ///     access the root.
    ///     go to  the right subtree while root has right subtree
    ///                         , i.e., call Inorder(right-subtree )

    if (root == nullptr)
        return nullptr;

    tree_traversal_in_order(root->_left, size, arr);
    arr[size] = root->_item;
    size++;
    tree_traversal_in_order(root->_right, size, arr);

    return arr;
}

#endif  // BINARY_SEARCH_TREE_H
