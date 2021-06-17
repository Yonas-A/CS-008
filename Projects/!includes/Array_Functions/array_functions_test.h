#ifndef ARRAY_FUNCTIONS_TEST_H
#define ARRAY_FUNCTIONS_TEST_H
#include <iostream>
#include <vector>

#include "../../!includes/Array_Functions/array_functions.h"

using namespace std;

void test_attach_item();
// a test function for attach_item();

void test_copy_array();
// a test function for copy_array();

void test_delete_item();
// a test function for delete_item();

void test_detach_item();
// a test function for detach_item();

void test_first_ge();
// a test function for first_ge()

void test_index_max();
// a test function for index_of_maximal()

void test_insert_item();
// a test function for insert_item();

void test_is_gt();
// a test function for is_gt();

void test_is_le();
// a test function for is_le();

void test_maximal();
// a test function for maximal

void test_merge();
// a test function for merge();

void test_ordered_insert();
// a test function for ordered_insert();

void test_split();
// a test function for split();

void test_overloaded_PLUS_OPERATOR();
// a test function for operator + and insertion << operator

void test_overloaded_PLUS_EQUAL();
// a test function for operator += and insertion << operator

// =============================================================
// =============================================================
//              Function definitions
// =============================================================
// =============================================================

void test_attach_item() {
    cout << "=  =   =   test  attach_item() =  =   =" << endl
         << endl;
    int arr[15] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = 13;

    cout << "source size : " << size << endl;
    print_array(arr, size);

    cout << "attach 101 in arr" << endl;
    attach_item(arr, size, 101);
    print_array(arr, size, 11);

    cout << "=  =   =   exiting attach_item() test =  =  =" << endl
         << endl;
}

void test_copy_array() {
    cout << "=  =   =   copy_array() test =  =  =" << endl
         << endl;

    int arr[] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    const int MAX = 20;
    int dest[MAX] = {};
    int dest_size = 4;

    copy_array(dest, arr, dest_size, size);

    cout << "source size : " << size << "   source: " << endl;
    print_array(arr, size);
    cout << "dest size : " << dest_size << "   dest: " << endl;
    print_array(dest, dest_size);

    cout << "=  =  =  exiting copy_array() test =  =  =" << endl
         << endl;
}

void test_delete_item() {
    cout << "=  =   =   delete_item() test =  =  =" << endl
         << endl;

    int arr[] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "array size : " << size << endl;
    print_array(arr, size);

    int entry;
    for (int i = 0; i < size / 2; i++) {
        int index = rand() % (6);
        cout << "index " << index << "  item: " << arr[index] << endl;
        delete_item<int>(arr, index, size, entry);
        cout << "deleted element: " << entry << "   size: " << size << endl;
        print_array(arr, size, index);
    }

    cout << "=  =   = exiting delete_item() test =  =" << endl
         << endl;
}

void test_detach_item() {
    cout << "=  =   =   attach_item() test =  =  =" << endl
         << endl;

    int arr[] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "array size : " << size << endl;

    print_array(arr, size);

    int entry;
    detach_item<int>(arr, size, entry);
    cout << "detached element: " << entry << endl;
    print_array(arr, size, size - 1);

    cout << "=  =   =   exiting detach_item() test =  =  =" << endl
         << endl;
}

void test_first_ge() {
    cout << "=  =   =   first_ge() test =  =  =" << endl
         << endl;

    int arr[] = {2, 4, 5, 15, 19, 23, 26, 27, 36, 38, 44, 46, 47, 48, 50};

    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    cout << "size is " << size << endl
         << endl;
    int high = size - 4;

    for (int i = 0; i < size / 3; ++i) {
        int r = rand() % (high + 1) + 1;
        int entry = arr[r] + r;

        int index = first_ge(arr, size, entry);
        print_array(arr, size, index);

        if (index < size) {
            cout << "first greater or equal item to " << entry
                 << "  is: " << arr[index] << "  ; index = "
                 << index << endl;
        }

        else if (index == size) {
            cout << "first greater or equal item to " << entry
                 << "  does not exist in the array: "
                 << "  index = size =  " << index << endl;
        }
    }
    cout << "=  =   =   exiting first_ge() test =  =  =" << endl
         << endl;
}

void test_index_max() {
    cout << "=  =  = index_of_maximal() test =  =  =\n\n";

    int arr[] = {23, 26, 27, 36, 38, 44, 79, 46, 47, 48, 50};
    int size = sizeof(arr) / sizeof(*arr);
    print_array(arr, size);

    int index = index_of_maximal(arr, size);
    cout << "index of maximal is: " << index
         << "   item at index: " << arr[index] << endl;
    print_array(arr, size, index);

    cout << "=  =  = exiting index_of_maximal() test =  =  =\n\n";
}

void test_insert_item() {
    cout << "=  =   =   insert_item() test =  =  =" << endl
         << endl;

    const int MAX = 25;
    int arr[MAX] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = 13;
    print_array(arr, size);

    int entry = 0;

    for (int i = 0; i < size / 3; i++) {
        cout << endl
             << endl;
        int index = rand() % (size);
        entry = arr[index] + index;
        cout << "index " << index << "  item: " << entry << endl;

        insert_item<int>(arr, index, size, entry);
        print_array(arr, size, index);
    }

    cout << "=  =   = exiting insert_item() test =  =" << endl
         << endl;
}

void test_is_gt() {
    cout << "=  =   =   is_gt() test =  =  =" << endl
         << endl;

    int arr[] = {23, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = sizeof(arr) / sizeof(*arr);
    print_array(arr, size);

    for (int i = 0; i < size; i++) {
        int item = arr[rand() % size] + rand() % (size);
        cout << "item : " << item;

        if (is_gt(arr, size, item) == true) {
            cout << "   ,is_gt is true: " << endl;
        } else {
            cout << "   ,is_gt is false: " << endl;
        }
    }

    cout << "=  =  =   exiting is_gt() test =  =  =" << endl
         << endl;
}

void test_is_le() {
    cout << "=  =   =   is_le() test =  =  =" << endl
         << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(*arr);
    print_array(arr, size);

    for (int i = 0; i < size; i++) {
        int low = 0 - size, high = size;

        int item = arr[rand() % size] - rand() % (high - low + 1) - low;
        cout << "item : " << item;

        if (is_le(arr, size, item) == true) {
            cout << "   ,is_le is true: " << endl;
        } else {
            cout << "   ,is_le is false: " << endl;
        }
    }

    cout << "=  =  =   exiting is_le() test =  =  =" << endl
         << endl;
}

void test_maximal() {
    cout << "=  =   =   merge() test =  =  =" << endl
         << endl;

    int arr[] = {26, 27, 36, 38, 44, 46, 47, 48, 50, 65, 73};
    int size = sizeof(arr) / sizeof(*arr);

    for (int i = 0; i < size; i++) {
        int lhs = arr[i];
        int r = rand() % (size + 1);
        int rhs = arr[r] + rand() % (size);

        cout << "lhs: " << lhs << "     rhs: " << rhs << endl;
        cout << "maximum is " << maximal(lhs, rhs) << endl;
    }

    cout << "=  =  =   exiting merge() test =  =  =" << endl
         << endl;
}

void test_merge() {
    cout << "=  =   =   merge() test =  =  =" << endl
         << endl;

    const int MAX = 20;
    int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    int data2[] = {26, 27, 36, 38, 44, 46, 47, 48, 50, 65, 73};
    int d_size = sizeof(data2) / sizeof(*data2);

    cout << "=  =   =   arr1 =  =   =" << endl;
    print_array(arr, size);
    cout << "=  =   =   arr2 =  =   =" << endl;
    print_array(data2, d_size);

    int t = size;

    cout << "merge arr and data2 " << endl;
    merge(arr, size, data2, d_size);

    cout << "=  =   =   arr1 =  =   =" << endl;
    print_array(arr, size, t);
    cout << "=  =   =   arr2 =  =   =" << endl;
    print_array(data2, d_size, t);

    cout << "=  =  =   exiting merge() test =  =  =" << endl
         << endl;
}

void test_ordered_insert() {
    cout << "=  =   = ordered_insert() test =  =  =\n\n";

    int arr[] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);

    for (int i = 0; i < size / 4; i++) {
        int r = rand() % (6) + 1;
        int entry = arr[r] * r / 3;
        cout << " entry: " << entry << endl;
        ordered_insert(arr, size, entry);
        int index = first_ge(arr, size, entry);
        print_array(arr, size, index);
    }

    cout << "=  =  = exiting ordered_insert() test =  =  =\n\n";
}

void test_split() {
    cout << "=  =   =   split() test =  =  =" << endl
         << endl;

    //    int arr [ ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[] = {2, 4, 5, 15, 26, 27, 36, 38, 44, 46, 47, 48, 50};

    int size = sizeof(arr) / sizeof(arr[0]);

    const int MAX = 20;
    int dest[MAX] = {};
    int dest_size = 0;

    cout << "=  =   =   arr =  =   =" << endl;
    print_array(arr, size);
    cout << "=  =   =   data =  =   =" << endl;
    print_array(dest, dest_size);

    cout << "split arr in half " << endl;
    split(arr, size, dest, dest_size);

    cout << "=  =   =   arr =  =   =" << endl;
    print_array(arr, size, size - 1);
    cout << "=  =   =   data =  =   =" << endl;
    print_array(dest, dest_size);

    cout << "=  =  =   exiting split() test =  =  =" << endl
         << endl;
}

void test_overloaded_PLUS_OPERATOR() {
    cout << "=  =   = vector overloaded + test =  =  =" << endl
         << endl;

    vector<int> lhs{20, 30, 12, 97, 10, 15, 17, 25, 22, 35, 32};
    vector<int> rhs{26, 27, 36, 38, 44, 46, 47, 48, 50, 65, 73};

    cout << "=  =   =   =  =  =   =   =   =   =" << endl
         << endl;

    cout << "LHS size: " << lhs.size() << endl
         << lhs << endl
         << endl;
    cout << "RHS size: " << rhs.size() << endl
         << rhs << endl
         << endl;

    cout << "=  =   =   =  =  =   =   =   =   =" << endl
         << endl;

    vector<int> vec;
    vec = lhs + rhs;
    cout << endl;
    cout << "VEC size: " << vec.size() << endl
         << vec << endl
         << endl;

    cout << "=  =   = EXITING vector overloaded + test =  =  =\n"
         << endl;
}

void test_overloaded_PLUS_EQUAL() {
    cout << "=  =   = vector overloaded += test =  =  =" << endl
         << endl;

    int arr[] = {20, 30, 12, 97, 10, 15, 17, 25, 22, 35, 32};

    int size = sizeof(arr) / sizeof(*arr);

    vector<int> vec{26, 27, 36, 38, 44, 46, 47, 48, 50, 65, 73};
    vector<int> list;

    for (int i = 0; i < size; i++) {
        list += arr[i];
    }

    cout << endl;
    cout << "=  =   =   =  =  =   =   =   =   =" << endl
         << endl;

    cout << "VEC size: " << vec.size() << endl
         << vec << endl
         << endl;
    cout << "LIST size: " << list.size() << endl
         << list << endl
         << endl;

    cout << "=  =   =   =  =  =   =   =   =   =" << endl
         << endl;

    vector<int> hold;
    hold += list;

    cout << endl;
    cout << "hold size: " << hold.size() << endl
         << hold << endl
         << endl;

    cout << "=  =  = exiting vector operators test =  =  =\n\n";
}
#endif  // ARRAY_FUNCTIONS_TEST_H
