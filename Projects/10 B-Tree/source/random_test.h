#ifndef RANDOM_TEST_H
#define RANDOM_TEST_H
#include <iostream>

#include "../../!includes/Array-Functions/array_functions.h"
#include "../../!includes/B_Tree/b_tree.h"
#include "../../!includes/Random/random.h"

using namespace std;

void shuffle_array(int arr[], int size);

void test_tree_auto(int tree_size, int how_many, bool report);

bool test_tree_auto(int tree_size, bool report);

// =============================================================
// =============================================================
//              Function definitions
// =============================================================
// =============================================================

void test_tree_auto(int tree_size, int how_many, bool report) {
    bool verified = true;
    for (int i = 0; i < how_many; i++) {
        if (report) {
            cout << "***********************************************" << endl;
            cout << "\t"
                 << " T E S T:  " << i << "\n";
            cout << "***********************************************" << endl;
        }

        if (!test_tree_auto(tree_size, report)) {
            cout << "T E S T :   [" << i << "]    F A I L E D ! ! !" << endl;
            verified = false;
            return;
        }
    }

    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl;
    cout << "     E N D     T E S T:     " << how_many
         << " tests of " << tree_size << " items: ";
    cout << (verified ? "VERIFIED" : "VERIFICATION FAILED") << endl;
    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl;
}

bool test_tree_auto(int how_many, bool report) {
    const int MAX = 1000;
    assert(how_many <= MAX);

    BTree<int> root;
    int a[MAX];
    int original[MAX];
    int deleted_list[MAX];

    int original_size;
    int size;
    int deleted_size = 0;

    //fill a[ ]
    for (int i = 0; i < how_many; i++) {
        a[i] = i;
    }

    //shuffle a[ ]: Put this in a function!

    shuffle_array(a, how_many);
    //copy  a[ ] -> original[ ]:

    copy_array(original, a, original_size, how_many);

    size = how_many;

    original_size = how_many;

    for (int i = 0; i < size; i++) {
        root.insert(a[i]);
    }

    if (report) {
        cout << "=  =   =   =   =   =   =   =   =   =   =   =" << endl;
        cout << "  " << endl;
        cout << "=  =   =   =   =   =   =   =   =   =   =   =" << endl;
        cout << root << endl
             << endl;
    }
    for (int i = 0; i < how_many; i++) {
        Random t;
        int r = t.Next(0, how_many - i - 1);
        if (report) {
            cout << "==============================================\n";
            cout << root << endl
                 << endl;
            cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . " << endl;
            cout << "deleted: ";
            print_array(deleted_list, deleted_size);
            cout << "   from: ";
            print_array(original, original_size);
            cout << endl;
            cout << "  REMOVING [" << a[r] << "]" << endl;
            cout << "==============================================\n";
        }
        root.remove(a[r]);

        delete_item(a, r, size, deleted_list[deleted_size++]);

        if (!root.is_valid()) {
            cout << setw(6) << i << " I N V A L I D   T R E E" << endl;
            cout << "Original Array: ";
            print_array(original, original_size);
            cout << "Deleted Items : ";
            print_array(deleted_list, deleted_size);
            cout << endl
                 << endl
                 << root << endl
                 << endl;
            return false;
        }
    }
    if (report)
        cout << " V A L I D    T R E E" << endl;

    return true;
}

void shuffle_array(int arr[], int how_many) {
    Random r;
    for (int i = 0; i < how_many; i++) {
        int x = r.Next(0, how_many - 1);
        int y = r.Next(0, how_many - 1);

        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}

#endif  // RANDOM_TEST_H
