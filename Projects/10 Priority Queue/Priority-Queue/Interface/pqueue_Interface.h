#ifndef PQUEUE_INTERFACE_H
#define PQUEUE_INTERFACE_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../../!includes/Priority_Queue/pqueue.h"


void Main_menu();
// driver function to test 100 inserts and output the
// items in descending order

unsigned int Random(unsigned int min, unsigned int max);
// generates a random number between min and max

///================= ================== ==================
/// test function definitions for PQueue interface
///================= ================== ==================


void Main_menu()
{
    PQueue<int> tree;
    for (int i = 0; i < 10000; i++)
    {
        tree.insert(i, Random(1,10000));
    }

    cout << tree << endl << endl;

    for( unsigned int i = 0; i < 10000; i++)
    {
        int item = tree.Pop();
        cout << i <<  "     Item: " << item << endl;
    }
}

unsigned int  Random(unsigned int min, unsigned int max)
{
    unsigned int randomNum = rand () % (max - min + 1) + min;
    return randomNum;
}



#endif // PQUEUE_INTERFACE_H
