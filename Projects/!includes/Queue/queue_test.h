#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H
#include <iostream>
#include "../../!includes/Doubly_Linked_List/doubly_linked_list.h"
#include "../../!includes/Queue/queue.h"


void test_big_three();
// test for the big three i.e. copy ctor,
// assignement operator and destructor

void test_Empty();
// test for Emtpy()

void test_Front();
// test for Front()

void test_Pop();
// test for Pop()

void test_Push(Queue<int> &myQ);
// test for Push();

//==============================================
//  test function definitions for queue.h
//==============================================
void test_big_three()
{
    cout << "- - -  _big_three()  test - - - \n" << endl;

    cout << "\t----- default ctor(): myQ ------\n";
    Queue<int> myQ;

    test_Push(myQ);

    cout << "myQ  " << myQ << endl;

    cout << "\t----- copy ctor(): myQ2(myQ) ------\n";
    Queue <int> myQ2(myQ);

    cout << "myQ  " << myQ << endl;
    cout << "myQ2  " << myQ2 << endl;


    cout << "\t----- ctor = () myQ2 = myQ2 ------\n";
    Queue <int> myQ3;
    myQ3 = myQ2;
    cout << "myQ3  " << myQ3 << endl;


    cout << "- - - exiting _big_three()  test - - - \n" << endl;
}

void test_Empty()
{
    cout << "\n- - -  Empty()  test - - - \n" << endl;
    Queue<int> myQ;
    cout << "myQ  " << myQ << endl;

    bool is_empty = myQ.Empty ();
    cout << "\t------- test 1: empty list ---------" << endl;

    if(is_empty)
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl << endl;

    cout << "\t------- test 2: list with 10 items --------" << endl;
    test_Push(myQ);

    cout << "myQ  " << myQ << endl;
    is_empty = myQ.Empty();

    if(is_empty)
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl << endl;

    cout << "- - -  Exiting Empty()  test - - - \n" << endl;
}

void test_Front()
{
    cout << "\n- - -  Front()  test - - - \n" << endl;
    Queue<int> myQ;
    cout << "myQ  " << myQ << endl;

//    int front = myQ.Front();
//    cout << endl << "\t------- test 1: empty list ---------" << endl;

//    if(front)
//        cout << "Front node is [" << front <<"]" << endl;
//    else
//        cout << "Queue is empty. No front node found" << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;

    test_Push(myQ);
    int front = myQ.Front ();

    if(front)
        cout << "Front node is [" << front <<"]" << endl;
    else
        cout << "Queue is empty. No front node found" << endl;

    cout << endl << "\t====== end of test Front() ======" << endl;

}

void test_Pop()
{
    cout << endl << "\t====== Test Pop() ======" << endl << endl;

    Queue<int> myQ;
    test_Push(myQ);

    cout << "----- test 1: pop 15 items from a queue -------" << endl;
    for(int i = 1; i <= 10; i++)
    {
       int  removed = myQ.Pop ();

        if(removed)
        {
            cout << "new queue:" <<"       "<< myQ << endl ;
        }

        else
            cout << "Queue is empty. Nothing to remove"
                 << endl << endl;
    }

    cout <<"\t====== Exiting Pop() test ======" << endl << endl;
}


void test_Push(Queue<int> &myQ)
{
//    cout << "\n- - -  Push()  test - - - \n"  << endl;

    for (int i = 1; i < 11; i++)
    {
        myQ.Push( i*10);
    }

    cout << myQ << endl;
//    cout << "- - - exiting Push()  test - - - \n" << endl;

}

#endif // QUEUE_TEST_H
