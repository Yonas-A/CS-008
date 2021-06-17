/*
 * Author: Yonas Adamu
 * Project: Priority Queue
 * Purpose: using a heap class and info struct write a program
 *          to store data based on priority in which a data with
 *          the heighest priority serves as the root of the complete
 *          binary tree
 */

#include <string.h>

#include <iostream>

#include "../../!includes/Priority_Queue/pqueue.h"
#include "../../!includes/Priority_Queue/pqueue_test.h"
#include "../../!includes/Timer/timer.h"
#include "./pqueue_Interface.h"

using namespace std;

int main() {
    Timer t;
    t.start();
    srand(time(nullptr));
    /// test interface for PQueue
    /// ============== ============== ==============
    Main_menu();
    /// ============== ============== ==============

    /// test functions for info struct
    /// ============== ============== ==============
    //    test_info();
    //    test_info_comparison();
    /// ============== ============== ==============

    /// test functions for Priority Queue
    /// ============== ============== ==============

    //    PQueue<int> tree;
    //    test_insert( tree);

    //    test_is_empty();

    //    test_Pop();

    //    test_size();

    t.stop();

    cout << "time duration: " << t.duration() << endl;
    return 0;
}
