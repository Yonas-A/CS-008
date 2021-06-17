#ifndef SIMPLE_TEST_H
#define SIMPLE_TEST_H

#include <iostream>

//#include "../../!includes/Hash/chained_hash.h"
#include "../../!includes/Hash/Record/record.h"
#include "../../!includes/Hash/double_hash.h"

void test_simple();

void second_simple();

void test_simple() {
    double_hash<record<int> > h_table;

    h_table.insert(record<int>(5, 500));
    h_table.insert(record<int>(6, 600));
    h_table.insert(record<int>(7, 700));

    cout << "h_table" << endl
         << h_table << endl;

    double_hash<record<int> > c_table;
    c_table = (h_table);

    cout << "c_table" << endl
         << c_table << endl;

    cout << " " << setw(70) << setfill('=') << " \n";

    c_table.insert(record<int>(1, 100));

    cout << "h_table" << endl
         << h_table << endl;
    cout << "c_table" << endl
         << c_table << endl;
}

void second_simple() {
    cout << " " << setw(70) << setfill('=') << " \n";
    cout << "       C O P Y   C T O R   T E S T " << endl;
    cout << " " << setw(70) << setfill('=') << " \n";

    double_hash<record<int> > h_table;

    h_table.insert(record<int>(5, 500));
    h_table.insert(record<int>(6, 600));
    h_table.insert(record<int>(7, 700));

    cout << "h_table" << endl
         << h_table << endl;

    double_hash<record<int> > c_table(h_table);

    cout << "c_table" << endl
         << c_table << endl;

    cout << " " << setw(70) << setfill('=') << " \n";

    c_table.insert(record<int>(1, 100));

    cout << "h_table" << endl
         << h_table << endl;
    cout << "c_table" << endl
         << c_table << endl;
}

#endif  // SIMPLE_TEST_H
