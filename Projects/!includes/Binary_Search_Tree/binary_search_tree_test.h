#ifndef BINARY_SEARCH_TREE_TEST_H
#define BINARY_SEARCH_TREE_TEST_H
#include <array>
#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"



void test_add();
// a test function for tree_add(tree_node, tree_node);

void test_clear();
// a test function for tree_clear( tree_node )

void test_copy();
// a test function for tree_copy( tree_node )

void test_erase();
// a test function for tree_erase(tree_node, int);

void test_insert(tree_node<int>* &root);
// a test function for tree_insert(tree_node , insert_me)
// also prints the final tree

void test_print_inorder();
// a test function for tree_print_inorder(tree_node<T>* )

void test_remove_max();
// a test function for tree_remove_max(tree_node, max)

///==============================================================

void test_rotate();
// testing default rotate function when inserting items

void test_rotate_left();
// a test function for rotate_left(tree_node)

void test_rotate_left_right();
// a test function for rotate_left_right_left(tree_node)

void test_rotate_right();
// a test function for rotate_right(tree_node)

void test_rotate_right_left();
// a test function for rotate_right_left_right(tree_node)

///==============================================================

void test_search();
// a test function for tree_search( tree_node, target);

void test_search_bool();
// a test function for tree_search( tree_node, target, found);

void test_size();
// a test function for tree_size(tree_node)

void test_sorted_list_to_tree();
// a test function for tree_from_sorted_list(T*, size)

void test_traversal_in_order();
// a test function for tree_traversal_in_order(tree_node, int, T*)

//============================================================
//============================================================
///\note \note
//      test function definitions for binary search tree
//============================================================
//============================================================

void test_add()
{
    cout << "\n= = = = tree_add( dest, src ) test = = = = = \n\n";

    tree_node<int>* root = nullptr;
    cout << "- - - - printing first tree - - - - - \n\n";
    test_insert(root);    //inserting items


    tree_node<int>* dest = nullptr;
    tree_insert<int>(dest, 66);
    tree_insert<int>(dest, 65);
    tree_insert<int>(dest, 69);
    tree_insert<int>(dest, 67);
    tree_insert<int>(dest, 40);
    tree_insert<int>(dest, 25);
    tree_insert<int>(dest, 10);
    tree_insert<int>(dest, 50);
    cout << "- - - - printing second tree - - - - - \n\n";
    tree_print(dest, 0, cout);



    tree_add<int>(dest, root);

    cout << "- - - - printing first + second tree - - - - - \n\n";

    tree_print(dest, 0, cout);


    cout << "\n= = = = exiting tree_add( dest, src ) test = = = = \n\n" ;
}

void test_clear()
{
    cout << "\n= = = = tree_clear ( root) test = = = = = \n\n";

    tree_node<int>* root = nullptr;

    test_insert(root);    //inserting items
    tree_clear(root);    // clearing the root

    if(root)
    {
        cout << "- - - - - Tree - - - - \n" << endl;
        tree_print(root);
    }
    else
        cout << "Tree is null" << endl;

    cout << "\n= = = = exiting tree_clear( root) test = = = = \n\n" ;
}

void test_copy()
{
    cout << "\n= = = = tree_copy ( root) test = = = = = \n\n";

    tree_node<int>* root = nullptr;
    test_insert(root);
    tree_node<int>* copy = NULL;
    copy = tree_copy(root);

    cout << "- - - - - - Source Tree - - - - - - - \n" << endl;
    tree_print(root);

    cout << "\n- - - - - - - - Tree 2 - - - - - - - \n" << endl;
    tree_print(copy);

    cout << endl << endl;
    tree_print_debug(copy);

    cout << endl << endl << "copy height: " <<  copy->_height << endl;


    tree_insert (root, 45);
    tree_insert(copy, 93);

    cout << "\n- - - - Source Tree insert(root,45)- - -\n" << endl;
    tree_print(root);
    cout << endl << endl;
    tree_print_debug(root);
    cout << endl << endl;

    cout << "\n- - - - - - Tree 2 insert( root, 93)- - - - - \n" << endl;
    tree_print(copy);
    cout << endl << endl;
    tree_print_debug(copy);

    cout << "\n= = = = exiting tree_clear( root) test = = = = \n\n";
}

void test_erase()
{
    cout << "\n\t= = = = tree_erase(root, target) test = = = =\n\n";

    tree_node<int>* root = nullptr;

    tree_insert(root, 25);
    tree_insert(root, 20);
    tree_insert(root, 62);
    tree_insert(root, 22);
    tree_insert(root, 42);

    tree_insert(root, 92);
    tree_insert(root, 95);
    tree_insert(root, 84);
    tree_print(root);
    cout << endl << endl;
//    test_insert(root);


    int target = 25;
    bool erased = tree_erase(root, target);

    if(erased)
    {
        cout << "-  -   Tree erase( " << target << " ) -   -   -\n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;

        tree_print_debug(root, 0, cout);
        cout << endl << endl;
    }
    else
        cout << "Target " << target << " not in the tree\n" << endl;

    cout << "\n\n- - - - - second test- - - - - - \n\n";

//    target = 90;
//    erased = tree_erase(root, target);

//    if(erased)
//    {
//        cout << "-  -   Tree erase( " << target << " ) -   -   -\n\n";
//        tree_print(root, 0, cout);
//        cout << endl << endl;

//        tree_print_debug(root, 0, cout);
//        cout << endl << endl;
//    }
//    else
//        cout << "Target " << target << " not in the tree\n" << endl;

    cout << "\n\n   -   -   -   - FINAL TREE  -   -   -   -   \n\n";
    tree_print(root);
    cout << endl << endl;


    cout << "\n\n= = exiting tree_erase(root, target)  test = =  =\n"
         << endl;
}

void test_insert(tree_node<int>* &root)
{
    const bool DEBUG = false;

    tree_insert<int>(root, 40);
    tree_insert<int>(root, 25);
    tree_insert<int>(root, 10);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -  -   -   -   -   \n\n";
        tree_print(root, 0, cout);
    }

    tree_insert<int>(root, 50);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -  -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

    tree_insert<int>(root, 75);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -  -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

    tree_insert<int>(root, 90);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -   -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }


    tree_insert<int>(root, 85);
    tree_insert<int>(root, 87);


    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -   -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

//    tree_insert<int>(root, 31);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -   -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

//    tree_insert<int>(root, 6);
//    tree_insert<int>(root, 45);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -   -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

//    tree_insert<int>(root, 64);

    if(DEBUG)
    {
        cout << "\n\n   -   -   -   -   -   -   -   -   \n\n";
        tree_print(root, 0, cout);
        cout << endl << endl;
    }


    cout << "\n\n   =   =   =   =   FINAL TREE   =   =   =   =\n\n";
    tree_print(root, 0, cout);
    cout << endl << endl;

    if(DEBUG)
    tree_print_debug(root);

}

void test_remove_max()
{
    cout << "\n\t= = = = tree_remove_max(root, max) test = = = =\n\n";

    tree_node<int>* root = nullptr;
    test_insert(root);

    int erased = 0 ;
    for ( int i = 0; i < 5; i++)
    {
        tree_remove_max(root, erased);

        cout << "target erased: " << erased << endl;
        cout << "- - - - Tree after erase - -  - \n" << endl;

        tree_print(root, 0, cout);
    }

    cout << "\n\t= = = exiting tree_remove_max(root, max) test = = =\n\n";

}

void test_print_inorder()
{
    cout << "\n\t= = = = tree_print_inorder(root) test = = = =\n\n";

    tree_node<int>* root = nullptr;
    test_insert(root);

    cout << "printing tree inorder" << endl;
    tree_print_inorder(root);
    cout << "\n\t= = = = exiting tree_print_inorder(root) test = = =\n\n";

}

//========================================================================
///  test for rotate functions

void test_rotate()
{
    const bool DEBUG = true;
    cout << "\n= = = =  default rotate test  = = = = \n\n";

    tree_node<int>* root = nullptr;

    tree_insert<int>(root, 40);
    tree_insert<int>(root, 25);
    tree_insert<int>(root, 50);
    tree_insert<int>(root, 45);


    if(DEBUG)
    {
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

    tree_insert<int>(root, 70);
    tree_insert<int>(root, 65);
    tree_insert<int>(root, 64);

    if(DEBUG)
    {
        tree_print(root, 0, cout);
        cout << endl << endl;
    }

    cout << "\n\n   -   -   -   - FINAL TREE  -   -   -   -   \n\n";
    tree_print(root);
    cout << endl << endl;
    tree_print_debug(root, 0, cout);
    cout << endl << endl;

    cout << "\n= = = = exiting default rotate test = = = = \n\n";
}

void test_rotate_left()
{
    cout << "\n\t= = = = rotate_left( root ) test = = = =\n\n";

    tree_node<int>* root = nullptr;
    tree_insert<int>(root, 40);
    tree_insert<int>(root, 25);
    tree_insert<int>(root, 50);
    tree_insert<int>(root, 45);
    tree_insert<int>(root, 60);

    cout << "   -   -   -   -   test 1  -   -   -   \n\n";
    tree_print(root);
    cout << endl << endl;
    tree_print_debug(root);
    cout << endl << endl;


    tree_insert<int>(root, 55);

    cout << "   -   -   -   -   test 2  -   -   -   \n\n";
    tree_print(root);
    cout << endl << endl;
    tree_print_debug(root);
    cout << endl << endl;

    tree_insert<int>(root, 70);
    tree_print(root, 0);

    root->balance_factor(); // displays right and left height

    cout << "\n   -   -   - tree after rotate_left  -   -   -   \n\n";
    tree_print(root, 0);
    root->balance_factor(); // displays right and left height



    const bool DEBUG = true;
    if(DEBUG)
    {
        cout << "\nroot " << root->_item
             << "   root h: " << root->_height
             << "   left " << root->_left->_item
             << "   left h: " << root->_left->_height
             << "   right   " << root->_right->_item
             << "   right h: " << root->_right->_height << endl;
    }


    cout << "\n= = = = exiting rotate_left( root ) test = = = =\n\n";
}

void test_rotate_left_right()
{
    cout << "\n\t= = = = rotate_left_right( root ) test = = = =\n\n";

    tree_node<int>* root = nullptr;
    tree_insert<int>(root, 70);
    tree_insert<int>(root, 80);
    tree_insert<int>(root, 60);
    tree_insert<int>(root, 50);
    tree_insert<int>(root, 65);
    tree_insert<int>(root, 62);
    tree_insert<int>(root, 67);
    tree_print(root, 0);

    root->balance_factor(); // displays right and left height
    root = rotate_left_right(root);

    cout << "\n   -   -  tree after rotate_left_right  -   -   \n\n";
    tree_print(root, 0);
    root->balance_factor(); // displays right and left height


    const bool DEBUG = true;
    if(DEBUG)
    {
        cout << "\nroot " << root->_item
             << "   root h: " << root->_height
             << "   left " << root->_left->_item
             << "   left h: " << root->_left->_height
             << "   right   " << root->_right->_item
             << "   right h: " << root->_right->_height << endl;
    }
    cout << "\n= = = exiting rotate_left_right( root ) test = = =\n\n";

}

void test_rotate_right()
{
    cout << "\n\t= = = = rotate_right( root ) test = = = =\n\n";

    tree_node<int>* root = nullptr;
    tree_insert<int>(root, 55);
    tree_insert<int>(root, 45);
    tree_insert<int>(root, 25);
    tree_insert<int>(root, 20);
    tree_insert<int>(root, 40);
    tree_insert<int>(root, 50);
    tree_insert<int>(root, 70);
    tree_print(root, 0);

    root->balance_factor(); // displays right and left height
    root = rotate_right(root);

    cout << "\n   -   -   - tree after rotate_right  -   -   -   \n\n";
    tree_print(root, 0);
    root->balance_factor(); // displays right and left height

    const bool DEBUG = true;
    if(DEBUG)
    {
        cout << "\nroot " << root->_item
             << "   root h: " << root->_height
             << "   left " << root->_left->_item
             << "   left h: " << root->_left->_height
             << "   right   " << root->_right->_item
             << "   right h: " << root->_right->_height << endl;
    }
//    if(DEBUG)
//    {
//        cout <<"-   -   step 2  -   -   -\n";
//        cout << "root " << root->_item
//             << "   root h: " << root->_height
//             << "   left " << root->_left->_item
//             << "   left h: " << root->_left->_height
//             << "   right   " << root->_right->_item
//             << "   right h: " << root->_right->_height << endl;
//        cout << "hold " << hold->_item
//             << "   hold h: " << hold->_height
//             << "   left " << hold->_left->_item
//             << "   left h: " << hold->_left->_height
//             << "   right   " << hold->_right->_item
//             << "   right h: " << hold->_right->_height << endl;
//    }

    cout << "\n= = = = exiting rotate_right( root ) test = = = =\n\n";
}

void test_rotate_right_left()
{
    cout << "\n\t= = = = rotate_right_left( root ) test = = = =\n\n";

    tree_node<int>* root = nullptr;
    tree_insert<int>(root, 25);
    tree_insert<int>(root, 20);
    tree_insert<int>(root, 50);
    tree_insert<int>(root, 55);
    tree_insert<int>(root, 45);
    tree_insert<int>(root, 30);
    tree_insert<int>(root, 47);
    tree_print(root, 0);

    const bool DEBUG = true;
    if(DEBUG)
    {
        cout << "\nroot " << root->_item
             << "   root h: " << root->_height
             << "   left " << root->_left->_item
             << "   left h: " << root->_left->_height
             << "   right   " << root->_right->_item
             << "   right h: " << root->_right->_height << endl;
    }

    root->balance_factor(); // displays right and left height
    root = rotate_right_left(root);

    cout << "\n   -   -  tree after rotate_right_left  -   -   \n\n";
    tree_print(root, 0);

    root->balance_factor(); // displays right and left height

    if(DEBUG)
    {
        cout << "\nroot " << root->_item
             << "   root h: " << root->_height
             << "   left " << root->_left->_item
             << "   left h: " << root->_left->_height
             << "   right   " << root->_right->_item
             << "   right h: " << root->_right->_height << endl;
    }

    cout << "\n= = = exiting rotate_right_left ( root ) test = = =\n\n";
}

//========================================================================

void test_search()
{
    cout << "\n= = = = tree_search(root, target) test = = = = = " << endl;

    tree_node<int>* root = nullptr;
    test_insert(root);

    int target = 10;
    tree_node<int>* found = tree_search(root, target);

    if(found)
    {
        cout << "Target " <<  found->_item << " found" << endl;
         tree_print (found) ;
     }
     else
         cout << "Target " << target << " not in the tree\n" << endl;

    cout << "\n= = = = exiting tree_search(root, target) test = = = = \n";

}

void test_search_bool()
{
    cout << "\n= = = tree_search(root, target, found) test = = =\n\n";

    tree_node<int>* root = nullptr;
    test_insert(root);

    int target = 25;
    tree_node<int>* found = nullptr;
    bool located = tree_search(root, target, found);

    if(located)
    {
       cout << "Target " <<  found->_item << " found" << endl;
        tree_print (found) ;
    }
    else
        cout << "Target " << target << " not in the tree\n" << endl;

    cout << "\n = = exiting tree_search(root, target, found) test = =\n";
}

void test_size()
{
    cout << "\n= = = = tree_size( tree_node ) test = = = = = " << endl;

    tree_node<int>* root = nullptr;
    test_insert(root);

    int size = tree_size<int>(root);
    cout << "total number of nodes in the tree is:  "
         <<  size <<  endl ;

    cout << "\n= = = exiting tree_size( tree_node ) test = = = " << endl;

}

void test_sorted_list_to_tree()
{
    cout << "\n= = = tree_from_sorted_list(T* , int ) test = = =\n\n";

    int arr[] = {30,31,32,33,34,35,36,37,38,39,40};
    int size = sizeof(arr) / sizeof(arr[0]);
    tree_node<int>* tree = nullptr;

    cout << "Sorted List" << endl << "\t" ;
    for(int i = 0; i < size; i++)
    {
        cout << "[" << arr[i] << "]->" ;
    }
    cout << "|||" << endl << endl;

    tree = tree_from_sorted_list(arr,  size );
    tree_print (tree) ;

    cout << "\n= = exiting tree_from_sorted_list(T* , int) test = = =\n\n";
}

void test_traversal_in_order()
{
    cout << "\n= = = tree_traversal_in_orderh(root, size ) test = = =\n\n";

    tree_node<int>* root = nullptr;
    test_insert(root);

    int arr[1000];
    int* ptr = nullptr;
    int size = 0;

    ptr = tree_traversal_in_order(root, size, arr);

    if(ptr)
    {
        cout <<  "A total of " << size << " items found\n" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << "[" << arr[i] << "]->" ;
        }
        cout << "|||" << endl << endl;
    }

    else
        cout << "Root/Tree is null" << endl << endl;



    cout << "\n = = exiting tree_traversal_in_orderh(root, size) test = =\n";
}


#endif // BINARY_SEARCH_TREE_TEST_H
