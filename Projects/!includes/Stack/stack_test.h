#ifndef STACK_TEST_H
#define STACK_TEST_H
#include <iostream>
#include "../../!includes/Doubly_Linked_List/doubly_linked_list.h"
#include "../../!includes/Stack/stack.h"


void test_big_three();
// test for the big three i.e. copy ctor,
// assignement operator and destructor

void test_Empty();
// test for Emtpy()

void test_Pop();
// test for Pop()

void test_Push(Stack<int> &myS);
// test for Push();

void test_Top();
// test for Top()

//==============================================
//  test function definitions for queue.h
//==============================================

void test_big_three()
{
    cout << "- - -  _big_three()  test - - - \n" << endl;

    cout << "\t----- default ctor(): myQ ------\n";
    Stack<int> myS;

    test_Push(myS);

    cout << "myS  " << myS << endl;

    cout << "\t----- copy ctor(): myQ2(myQ) ------\n";
    Stack <int> myS2(myS);

    cout << "myS  " << myS << endl;
    cout << "myS2  " << myS2 << endl;


    cout << "\t----- ctor = () myQ2 = myQ2 ------\n";
    Stack <int> myS3;
    myS3 = myS;
    cout << "myS3  " << myS3 << endl;


    cout << "- - - exiting _big_three()  test - - - \n" << endl;
}

void test_Empty()
{
    cout << "\n- - -  Empty()  tests  - - - \n" << endl;
    Stack<int> myS;

    cout << "myS  " << myS << endl;
    bool is_empty = myS.Empty ();

    cout << "\t------- test 1: empty list ---------" << endl;

    if(is_empty)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl << endl;

    cout << "\t------- test 2: list with 10 items --------" << endl;
    test_Push(myS);
    is_empty = myS.Empty();

    if(is_empty)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl << endl;

    cout << "- - -  Exiting Empty()  test - - - \n" << endl;
}

void test_Push(Stack<int> &myQ)
{
//    cout << "\n- - -  Push()  test - - - \n"  << endl;

    for (int i = 1; i < 11; i++)
    {
        myQ.Push( i*10);
    }
    cout << myQ << endl;
//    cout << "- - - exiting Push()  test - - - \n" << endl;

}

void test_Pop()
{
    cout << endl << "   = = = Test Pop() = = = " << endl;

    Stack<int> myS;
    test_Push (myS);
    cout << "myS " << endl << "   " << myS ;


    int top =  myS.Top();
    int removed;

    cout << "- - - test 1: pop 15 items from  10 item Stack - - - "
         << endl;
    for(int i = 0; i < 15; i++)
    {
        removed = myS.Pop ();
        top = myS.Top ();

        cout << "Delting item number: " << i  << endl;
        if(removed)
        {
            cout << "new Stack:" << endl <<"       "<< myS ;
        }
        else
            cout << "Stack is empty. Nothing to remove"
                 << endl << endl;
    }

    cout << endl << "   = = = end of test Pop() = = = " << endl;

}

void test_Top()
{
    cout << "\n- - -  Top()  test - - - \n" << endl;
    Stack<int> myQ;
    cout << "myQ  " << myQ << endl;

//    int top = mys.Top();
//    cout << endl << "\t------- test 1: empty list ---------" << endl;

//    if(front)
//        cout << "Front node is [" << front <<"]" << endl;
//    else
//        cout << "Queue is empty. No front node found" << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;


    test_Push(myQ);
    int top = myQ.Top ();

    if(top)
        cout << "Top of Stack is  [" << top <<"]" << endl;
    else
        cout << "Stack is empty. No top node found" << endl;

    cout << endl << "\t====== end of test Top() ======" << endl;
}

#endif // STACK_TEST_H
