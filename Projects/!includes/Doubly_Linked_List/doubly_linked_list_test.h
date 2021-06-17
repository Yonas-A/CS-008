#ifndef LINK_TEST_H
#define LINK_TEST_H
#include <iostream>

#include "../../!includes/Doubly_Linked_List/doubly_linked_list.h"

void test_clear_list();
//test function for _clear_list() of list functions

void test_copy_list();
//test function for _copy_list() of list functions

void test_empty();
// test function for _empty() of list functions

void test_end();
// test function for _end() of list functions

void test_insert_after();
//test function for _insert_after() of list function

void test_insert_before();
// test function for insert_before() of list functions

void test_insert_head(node<int>*& head_ptr);
// test function for insert_head() of list functions

void test_insert_last();
//test function for _insert_last() of list function

void test_print_backward();
//test function for _print_backward() of list function

void test_print_list();
//test function for _print_list() of list function

void test_remove_head();
// test function for remove_head() of list functions

void test_remove_node();
// test for the _remove_node() of list functions

void test_search();
// test function for _search() of list functions

void test_size();
// test function for _size() of list functions

//=====================================
//  Definition
//=====================================

void test_clear_list() {
    cout << "\n\t===== _clear_list()  test =====\n"
         << endl;
    node<int>* head_ptr;
    _initialize_head(head_ptr);
    test_insert_head(head_ptr);

    cout << "Clearing list" << endl;
    _clear_list(head_ptr);
    _print(head_ptr);

    cout << "\t===== Exiting _clear_list()  test =====\n"
         << endl;
}

void test_copy_list() {
    cout << "\n\t===== _copy_list()  test =====\n"
         << endl;
    node<int>* head_ptr;
    _initialize_head(head_ptr);
    test_insert_head(head_ptr);

    node<int>* dest_head_ptr;
    _initialize_head(dest_head_ptr);
    node<int>* dest_end = _copy_list(head_ptr, dest_head_ptr);

    cout << "Source: " << endl;
    _print(head_ptr);
    cout << "Copy: " << endl;
    _print(dest_head_ptr);

    cout << "\n-----Checking uniqueness of two lists------\n";
    node<int>* src_end = _insert_last(head_ptr, 100);
    dest_end = _insert_last(dest_head_ptr, 200);

    cout << "Source after insert_last(100) " << endl;
    _print(head_ptr);
    cout << "Copy after insert_last(67) " << endl;
    _print(dest_head_ptr);

    cout << "Src_end = : [" << src_end->_item << "]" << endl;
    cout << "Dest_end = : [" << dest_end->_item << "]" << endl;

    cout << "\t===== Exiting _copy_list()  test =====\n"
         << endl;
}

void test_empty() {
    cout << "\n\t===== _empty()  test =====\n"
         << endl;
    node<int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    _print(head_ptr);

    bool is_empty = _empty(head_ptr);
    if (is_empty)
        cout << "List is empty" << endl
             << endl;
    else
        cout << "List is not empty" << endl
             << endl;

    cout << "------- test 2: 5 items in the list  ---------" << endl;
    test_insert_head(head_ptr);

    is_empty = _empty(head_ptr);
    if (is_empty)
        cout << "List is empty" << endl
             << endl;
    else
        cout << "List is not empty" << endl
             << endl;

    cout << "\t===== Exiting _empty()  test =====\n"
         << endl;
}

void test_end() {
    cout << "\n\t===== _end()  test =====\n"
         << endl;
    node<int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    _print(head_ptr);

    node<int>* end = _end(head_ptr);

    if (end == nullptr)
        cout << "List is empty" << endl
             << endl;
    else
        cout << "End node is [" << end->_item << "]\n"
             << endl;

    cout << "------- test 2: 5 items in the list  ---------" << endl;
    test_insert_head(head_ptr);
    _print(head_ptr);

    end = _end(head_ptr);
    if (end == nullptr)
        cout << "List is empty" << endl
             << endl;
    else
        cout << "End node is [" << end->_item << "]\n"
             << endl;

    cout << "\t===== Exiting _end()  test =====\n"
         << endl;
}

void test_insert_after() {
    cout << "\n\t ====== _insert_after() test =====\n\n";

    node<int>* head_ptr = nullptr;
    node<int>* iMarker = nullptr;   // holds desired node
    node<int>* inserted = nullptr;  // holds node after inserted
    _print(head_ptr);

    int item = 120;
    int key = 40;
    cout << "--- test 1: Insert " << item << " in empty list ---\n\n";

    inserted = _insert_after<int>(head_ptr, iMarker, item);

    cout << "Inserted node: = [" << inserted->_item << "]" << endl;

    _print(head_ptr);

    test_insert_head(head_ptr);

    item = 12;
    key = 120;
    cout << "--- test 2: Insert " << item << " after [" << key << "]---\n\n";

    iMarker = _search(head_ptr, key);
    inserted = _insert_after<int>(head_ptr, iMarker, item);

    cout << "Inserted node: = [" << inserted->_item << "]" << endl;
    _print(head_ptr);
    _print_backward(head_ptr);

    item = 123;
    key = 20;
    cout << "--- test 3: Insert " << item << " after [" << key << "]---\n\n";

    iMarker = _search(head_ptr, key);
    inserted = _insert_after<int>(head_ptr, iMarker, item);

    cout << "Inserted node: = [" << inserted->_item << "]" << endl;
    _print(head_ptr);
    _print_backward(head_ptr);

    cout << "\t======== end of test _insert_after()=========\n\n";
}

void test_insert_before() {
    cout << "\n\t ====== _insert_before() test =====\n\n";

    node<int>* head_ptr = nullptr;
    node<int>* iMarker = nullptr;   // holds desired node
    node<int>* inserted = nullptr;  // holds node after inserted
    _print(head_ptr);

    int item = 120;
    int key = 40;
    cout << "--- test 1: Insert an item in empty list ---\n\n";

    inserted = _insert_before<int>(head_ptr, iMarker, item);
    cout << "Inserted node: " << *inserted << endl;
    _print(head_ptr);

    test_insert_head(head_ptr);
    item = 12;
    key = 120;
    cout << "--- test 2: Insert an item before [ " << key << " ]---\n\n";

    iMarker = _search(head_ptr, key);
    inserted = _insert_before<int>(head_ptr, iMarker, item);

    cout << "Inserted node: " << *inserted << endl;
    _print(head_ptr);
    _print_backward(head_ptr);

    item = 123;
    key = 20;
    cout << "--- test 3: Insert an item before [ " << key << " ]---\n\n";

    iMarker = _search(head_ptr, key);
    inserted = _insert_before<int>(head_ptr, iMarker, item);

    cout << "Inserted node: " << *inserted << endl;
    _print(head_ptr);
    _print_backward(head_ptr);

    cout << "\t======== end of test _insert_before()=========\n\n";
}

void test_insert_head(node<int>*& head_ptr) {
    for (int i = 0; i < 5; i++)
        _insert_head<int>(head_ptr, i * 10);
    // _print(head_ptr);
}

void test_insert_last() {
    cout << "\n\t=====  _insert_last() test=====\n"
         << endl;

    node<int>* head_ptr = nullptr;
    _print(head_ptr);

    int key = 100;

    cout << "----- Test 1: insert [100] in an empty list" << endl;

    node<int>* end_node = _insert_last<int>(head_ptr, key);
    cout << "Last node: = " << *end_node << endl;
    _print(head_ptr);

    test_insert_head(head_ptr);
    key = 24;
    cout << "----- Test 2: insert [" << key << "] in a list of items\n";

    end_node = _insert_last<int>(head_ptr, key);

    cout << "Last node: = " << *end_node << endl;

    _print(head_ptr);
    _print_backward(head_ptr);

    cout << "\n\t===== Exiting _insert_last() test=====\n"
         << endl;
}

void test_print_backward() {
    cout << "\n\t===== _print_backward()  test =====\n"
         << endl;
    node<int>* head_ptr;
    _initialize_head(head_ptr);

    cout << "------- test 1: print empty list  ---------" << endl;
    _print_list(head_ptr);

    test_insert_head(head_ptr);
    cout << "------- test 2: 5 items in the list  ---------" << endl;
    _print_backward(head_ptr);

    cout << "\t===== Exiting _print_backward()  test =====\n"
         << endl;
}

void test_print_list() {
    cout << "\n\t===== _print_list()  test =====\n" << endl;
    node<int>* head_ptr;
    _initialize_head(head_ptr);

    cout << "------- test 1: print empty list  ---------" << endl;
    _print_list(head_ptr);

    test_insert_head(head_ptr);
    cout << "------- test 2: 5 items in the list  ---------" << endl;
    _print_list(head_ptr);

    cout << "\t===== Exiting _print_list()  test =====\n"
         << endl;
}

void test_remove_head() {
    cout << "\n\t===== _remove_head() test =====\n"
         << endl;

    node<int>* head_ptr = nullptr;
    test_insert_head(head_ptr);

    for (int i = 0; i < 6; i++)  // list only has 5 elements
    {
        int removed = _remove_head<int>(head_ptr);
        cout << "Removed count: " << i << endl;

        if (removed) {
            cout << "Removed item:  " << removed << endl;
            _print(head_ptr);
        }

        else {
            cout << "List is empty." << endl
                 << endl;
            break;
        }
    }

    _print(head_ptr);

    cout << "\n\t====== exiting _remove_head() test =====\n"
         << endl;
}

void test_remove_node() {
    cout << "\n\t===== _remove_node() test =====\n"
         << endl;

    node<int>* head_ptr = nullptr;
    test_insert_head(head_ptr);

    for (int key = 40; key >= 0; key -= 10) {
        cout << "---------: remove [" << key << "]---------" << endl;

        node<int>* delete_me = nullptr;

        delete_me = _search<int>(head_ptr, key);
        int removed_item = _remove_node(head_ptr, delete_me);

        if (removed_item > -1)
            cout << "Removed item = " << removed_item << endl;
        else
            cout << "Nothing to remove from list" << endl
                 << endl;

        _print(head_ptr);
    }

    cout << "\n\t====== exiting _remove_node() test =====\n"
         << endl;
}

void test_search() {
    cout << "\n\t===== _search() test =====\n"
         << endl;
    node<int>* head_ptr = nullptr;
    test_insert_head(head_ptr);

    int key = 12;
    cout << " \t------ Test 1: key = " << key << " ----------" << endl;
    node<int>* temp = _search<int>(head_ptr, key);

    if (temp == nullptr)
        cout << key << " is not found" << endl
             << endl;
    else
        cout << "printing searched item: " << *temp << endl
             << endl;

    key = 40;
    _print(head_ptr);

    cout << "\t------ Test 2: key = " << key << " ----------" << endl;

    temp = _search<int>(head_ptr, key);

    if (temp == nullptr)
        cout << key << " is not found" << endl
             << endl;
    else
        cout << "printing searched item: " << *temp << endl
             << endl;

    key = 0;
    _print(head_ptr);

    cout << "\t------ Test 3: key = " << key << "----------" << endl;
    temp = _search<int>(head_ptr, key);

    if (temp == nullptr)
        cout << key << " is not found" << endl
             << endl;
    else
        cout << "printing searched item: " << *temp << endl
             << endl;

    cout << "\t ====== exiting _search() test =====\n"
         << endl;
}

void test_size() {
    cout << "\n\t===== _size()  test =====\n"
         << endl;
    node<int>* head_ptr = nullptr;
    _print(head_ptr);

    cout << "---------- Test 1: empty list ----------" << endl;
    int size = _size<int>(head_ptr);
    cout << "\nSize of the list is: " << size << endl
         << endl;

    cout << "---------- Test 2: list of 5 items----------" << endl;
    test_insert_head(head_ptr);  //inserting 5 items in list

    size = _size<int>(head_ptr);
    cout << "\nSize of the list is: " << size << endl
         << endl;

    cout << "\t===== Exiting _size()  test =====\n"
         << endl
         << endl;
}

#endif  // LINK_TEST_H
