#ifndef HASH_INTERACTIVE_TEST_H
#define HASH_INTERACTIVE_TEST_H

#include <iomanip>
#include <iostream>

#include "../../!includes/Hash/Record/record.h"
#include "../../!includes/Random/random.h"


using namespace  std;

/*
 *  INTERACTIVE TEST FOR ALL HASH TABLES
 */


void display_menu();
//display prompt to user

template <typename T>
void delete_value(T& hash, const int &key );
// calls deletes a record from a table if it exists

template <typename T>
void find_value(T& hash, const int &key );
// calls find functions and returns

template <typename T>
void insert_value(T& hash, record<int> rec);

template <typename T>
void Main_Menu( T&hash, const string& description );
//calls functions and does everything

template <typename T>
void Random_insert(T& hash);
// inserts a random number

/// =========================================================
/// =========================================================
/// function definition for interactive test for hash
/// =========================================================
/// =========================================================

void display_menu()
{
    cout << "[S]IZE    [I]nsert     [R]andom    [D]elete    "
            "[F]ind    [Q]uit:    ";
}

template <typename T>
void delete_value(T& hash, const int &key )
{
    if( hash.remove(key) )
        cout << "   >> " << key << " was removed" << endl;
    else
        cout << "   >> " << key << " does not exist in the table"
             << endl;
}

template <typename T>
void find_value(T& hash, const int &key )
{
    record<int> result;

    bool found = hash.find(key, result);

    if(found )
        cout << "   >> " <<  result << endl;
    else
        cout << "   >> " << key << " NOT FOUND" << endl;
}

template <typename T>
void insert_value(T& hash, record<int> rec)
{
    hash.insert( rec);
    cout << "   >> " << rec << " has been Inserted" << endl;
}

template <typename T>
void Main_Menu( T& hash, const string& description )
{
    cout << setw(70) << setfill('=') << "\n";
    cout << "    I N T E R A C T I V E    H A S H     T E S T"
         << "   " << description << endl;
    cout << setw(70) << setfill('=') << "\n";
    cout << "\n\t. . . . . . . . . . TOP . . . . . . . . . . \n\n";

    bool done = false;
    char command, trash;
    int key, value;

    do
    {
        hash.print_interactive();
        cout << endl << endl ;

        display_menu();
        cin >> command;

        switch( toupper(command) )
        {
        case 'D':
            cin >> key;
            delete_value(hash, key);
            break;

        case 'F':
            cin >> key;
            find_value( hash, key );
            break;

        case 'I':
            cin >> key >> trash >> value;
            insert_value( hash, record<int>(key, value));
            break;

        case 'R':
            Random_insert(hash);
            break;

        case 'S':
            cout << "   >> size = " << hash.size() << endl;
            break;

        case 'Q':   // quit or exit program
        case 'X':
            done = true;
            break;
        }
    }
    while (!done);

    cout << "\n . . . . . . . . . . END  . . . . . . . . . . \n\n";
}


template <typename T>
void Random_insert(T& hash)
{
    Random ran ;
    int key = ran.Next(0, 1000);
    int value = ran.Next(0, 1000);

    record<int> rec(key, value);
    cout << " >> Inserting: " << rec << endl;
    hash.insert( rec);
}


#endif // HASH_TEST_INTERACTIVE_H
