#ifndef HASH_RANDOM_TEST_H
#define HASH_RANDOM_TEST_H

#include <iomanip>
#include <iostream>

#include "../../!includes/Hash/Record/record.h"
#include "../../!includes/Random/random.h"


using namespace  std;
static const int MIN_KEY = 0;
/// used as the min range for generating random numbers
static const int MAX_KEY = 1000;
/// used as the max range for generating random numbers

template <typename T>
void random_test(T&hash, const string& description, const int& SIZE);
///
template  <typename T>
void search_existing(const T& hash, record<int>* rec, int how_many);
/// searchs for the existance of random keys in hash table
template  <typename T>
void search_non_existing(const T& hash,  const int& HOW_MANY);
/// searchs for non existance of random keys in hash table

/// ==============================================================
///         function defintions for random test
/// ==============================================================

template <typename T>
void random_test( T& hash, const string& description, const int &SIZE)
{
    const bool DEBUG = false;

    record<int> * rec = new record<int>[SIZE];
    Random r;

    cout << setw(70) << setfill('=') << "\n";
    cout << "\t" << "R A N D O M    H A S H     T E S T"
         << "\t" << description <<  "\n";
    cout << setw(70) << setfill('=') << "\n";


    for(int i = 0; i < SIZE; i++)
    {
        rec[i] = record<int>( r.Next(MIN_KEY, MAX_KEY),
                              r.Next(MIN_KEY, MAX_KEY)* 1.0);

        if(DEBUG)
            cout << rec[i] << " inserted" << endl;
        hash.insert(rec[i]);
    }

    cout << "---- [" << SIZE  << "] keys inserted" << endl << endl << endl;

    search_existing(hash, rec, SIZE);
    search_non_existing(hash,  SIZE);

}


template  <typename T>
void search_existing(const T& hash, record<int>* rec, int how_many)
{
    const bool DEBUG = false;

    cout << " - - - - - - - - - " << " searching for existing key "
         << " - - - - - - - - - " << endl;

    Random r;
    record<int> result;
    int found_count = 0 , non_found_count = 0;
    cout << "Search for existing keys: " << how_many / 2
         << " keys to be tested" << endl;

    for(int i = 0;i < how_many / 2; i++)
    {
        int key = rec[r.Next(MIN_KEY, how_many -1)]._key;

        if(hash.find(key, result) )
        {
            if(DEBUG)
                cout << setw(4) << setfill('0') << i
                     << "  " << result << " was found" << endl;
            found_count++;
        }
        else
        {
            non_found_count++;
            if(DEBUG)
                cout << "Exisitng key " << key  << " was not found"
                     << "   ****** ERROR ******" << endl << endl;
        }
    }

    if(non_found_count > 0 )
    {
        cout << "EXISTING KEYS LOOK UP:       V E R I F I C A T I O N"
             << " F A I L E D ! !" << endl;
    }
    else
    {
        cout << "EXISTING KEYS LOOK UP:      EXISTING KEYS EXAMINED: "
             <<  found_count << endl;
    }
    cout << endl << endl;
}

template  <typename T>
void search_non_existing(const T& hash, const int &HOW_MANY)
{
    const bool DEBUG = false;
    const bool CHECK_INSERTED = false;

    cout << " - - - - - - - - " << " searching for non existing key "
         << " - - - - - - - - " << endl;

    Random r;
    record<int>* rec = new record<int>[HOW_MANY];
    record<int> result;

    for(int i = 0; i < HOW_MANY; i++)
    {
        rec[i] = record<int>( r.Next(MAX_KEY + 1, MAX_KEY*2),
                              r.Next(MAX_KEY + 1, MAX_KEY*2)* 1.0);
        if(CHECK_INSERTED)
            cout << "non existant key " << rec[i]
                    << " being inserted " << endl;
    }

    int found_count = 0 , non_found_count = 0;
    cout << "Search for non existing keys: " << HOW_MANY / 2
         << " keys to be tested" << endl;

    for(int i = 0;i < HOW_MANY / 2; i++)
    {
        int key = rec[r.Next(MIN_KEY, HOW_MANY -1)]._key;

        if(hash.find(key, result) )
        {
            if(DEBUG)
                cout << "Non Exisitng key " << setw(4) << setfill('0')
                     << i << "  " << result << " was found"
                     << "   ****** ERROR ******" << endl << endl;
            found_count++;
        }
        else
        {
            non_found_count++;
            if(DEBUG)
                cout << "Non Exisiting key " << key
                     << " was not found" << endl;
        }
    }

    if(found_count > 0 )
    {
        cout << "NONEXISTENT KEYS LOOK UP:       V E R I F I C A T I O N"
             << " F A I L E D ! !" << endl;
    }
    else
    {
        cout << "NONEXISTENT KEYS LOOK UP:      NON EXISTING KEYS EXAMINED: "
             <<  non_found_count << endl;
    }
    cout << endl << endl;
}





#endif // HASH_RANDOM_TEST_H
