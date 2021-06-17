#ifndef HEAP_INTERFACE_H
#define HEAP_INTERFACE_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../../!includes/Heap/heap.h"


using namespace std;

//====================================================
//          FUNCTION DECLERATION FOR USER INTERFACE
//====================================================

void display_menu();
//display prompt to user

void display_tree(const Heap<int> &tree);
// displays the content of tree;

void Main_menu();
//calls functions and does everything

void pop_root(Heap<int> &tree );
// calls heap Pop functions and removes tree's heighest root

void Random_insert(Heap<int> &tree);
// inserts a random number

//====================================================
//          FUNCTION DEFINTION
//====================================================

void display_menu()
{
    cout << "[R]andom   [I]nsert    [C]lear    [P]op    "
         << "[Q]uit:    ";
}

void display_tree(const Heap<int> &tree )
{
    cout << endl << tree << endl << endl
         << "=========================" << endl << endl;
}

void Main_menu()
{
    cout << "\n\t. . . . . . . . . . TOP . . . . . . . . . . \n\n";
    bool done = false;
    char command;


    Heap<int> tree;
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

        case 'P':   // delete heighest root from a heap tree
            pop_root(tree);
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

void pop_root(Heap<int> &tree )
{
    if( tree.size() <= 0)
        cout << "Noting to pop " << endl;

    else
    {
        int erased = tree.Pop();
        cout << "-- item erased: [" << erased << "]" << endl;
    }
}

void Random_insert(Heap<int> &tree)
{
    int randomNum = rand () % 100;
    cout << "       Inserting: " << randomNum << endl;
    tree.insert(randomNum);
}




#endif // HEAP_INTERFACE_H
