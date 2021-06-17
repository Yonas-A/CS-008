#ifndef AVL_INTERFACE_H
#define AVL_INTERFACE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../../!includes/AVL/avl.h"
#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"

using namespace std;

//====================================================
//          FUNCTION DECLERATION FOR USER INTERFACE
//====================================================


void display_menu();
//display prompt to user

void display_tree(const avl<int> &tree);
// displays the content of tree;

void erase(avl<int> &tree, const int &target);
// erase a node holding target

void Main_menu();
//calls functions and does everything

void Random_insert(avl<int> &tree);
// inserts a random number

void search(avl<int> &tree, const int &target);
// search for a given item in the tree

//====================================================
//          FUNCTION DEFINTION
//====================================================

void display_menu()
{
    cout << "[R]andom   [I]nsert    [C]lear  [S]earch   "
         << "[E]rase    [Q]uit:    ";
}

void display_tree(const avl<int>  &tree )
{
    cout << endl << tree << endl << endl
         << "=========================" << endl << endl;
}

void erase(avl<int> &tree, const int &target)
{
    tree_node<int>* found = nullptr;
    bool located = tree.search(target, found);
    if(located)
    {
        tree.erase(target);
    }

    else{
        cout << "--item doesn't exist in the tree" << endl << endl;
    }
}

void Main_menu()
{
    cout << "\n\t. . . . . . . . . . TOP . . . . . . . . . . \n\n";
    bool done = false;
    char command;


    avl<int> tree;
    cout << tree << endl << endl;
    int input;


    do
    {

        display_menu();
        cin >> command;


        switch( toupper(command) )
        {
        case 'R':   // random insert
            Random_insert(tree);
            break;

        case 'I':   // insert an item from user input
            cout << ": ";
            cin >> input;
            cout << "- - Inserting " << input;
            tree.insert(input);
            break;

        case 'C':   //  clear tree
            tree.clear();
            break;

        case 'S': // search for an item from user input
            cout << "? ";
            cin >> input;
            search(tree, input);
            break;

        case 'E':   // delete item from tree from user input
            cout << ": ";
            cin >> input;
            erase(tree, input);
            break;

        case 'Q':   // quit or exit program
        case 'X':
            done = true;
            break;
        }
        display_tree(tree);
    }
    while (!done);

    cout << "\n . . . . . . . . . . END  . . . . . . . . . . \n\n";
}


void Random_insert(avl<int> &tree)
{
    const bool DEBUG = true;


    int randomNum = rand () % 100;
    tree.insert(randomNum);

    if(DEBUG)
        cout << "Randome number inserted: " << randomNum << endl;


}

void search(avl<int> &tree, const int& target)
{
    tree_node<int>* found = nullptr;
    bool located = tree.search(target, found);
    if(located)
    {
        cout << "--item found |" << found->_item << "|" << endl << endl;
    }

    else{
        cout << "-- item doesn't exist in the tree" << endl << endl;
    }
}


#endif // AVL_INTERFACE_H
