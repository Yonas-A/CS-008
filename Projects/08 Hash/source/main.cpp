/*
 * Author: Yonas Adamu
 * Project: Hash tables (open, double and chained hash classes)
 * Purpose: to store data in a structure called hash table based on
 *          the idea of hashing ( uniform distribution of data in
 *          an array (or similar structures like avl trees ...)
 *
 */

#include <iostream>

#include "../../!includes/Hash/Record/record.h"
#include "../../!includes/Hash/chained_hash.h"
#include "../../!includes/Hash/double_hash.h"
#include "../../!includes/Hash/hash_interactive_test.h"
#include "../../!includes/Hash/hash_random_test.h"
#include "../../!includes/Hash/open_hash.h"

using namespace std;

int main() {
    cout << endl << endl << endl;

    const bool INTERACTIVE_OPEN = false;
    const bool INTERACTIVE_DOUBLE = false;
    const bool INTERACTIVE_CHAINED = false;

    const bool RANDOM_DOUBLE = false;
    const bool RANDOM_OPEN = true;
    const bool RANDOM_CHAINED = false;

    if (INTERACTIVE_OPEN) {
        open_hash<record<int> > h_table;
        Main_Menu(h_table, "open_hash<record>");
    }

    if (INTERACTIVE_DOUBLE) {
        double_hash<record<int> > h_table;
        Main_Menu(h_table, "double_hash<record>");
    }

    if (INTERACTIVE_CHAINED) {
        chained_hash<record<int> > h_table;
        Main_Menu(h_table, "chained_hash<record>");
    }

    if (RANDOM_OPEN) {
        open_hash<record<int> > h_table;
        random_test(h_table, "open_hash<record>", 500);
    }

    if (RANDOM_DOUBLE) {
        double_hash<record<int> > h_table;
        random_test(h_table, "double_hash<record>", 500);
    }

    if (RANDOM_CHAINED) {
        chained_hash<record<int> > h_table;
        random_test(h_table, "chained_hash<record>", 2500);
    }

    cout << endl
         << endl;
    cout << ". . . . . . . . . . END . . . . . . . . . ." << endl;
}
