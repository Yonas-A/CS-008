#include <iostream>
#include <string>

#include "../../!includes/FTokenizer/ftokenizer.h"
#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"

using namespace std;

MMap< string, long> get_word_indices(char* file_name);


int main( )
{
    MMap<string, long> word_indices;

    char p[] = "solitude.txt";

    word_indices = get_word_indices( p );
    cout << endl << endl << endl;

    //list all nodes of the index mmap:
    for ( MMap<string, long>::Iterator it = word_indices.begin();
         it != word_indices.end(); it++ )
    {
        cout << * it << endl;
    }


    cout << endl << endl << endl;
    cout << "---------------------------------------------------" << endl;
    string this_word = "ice";
    cout << "---------------------------------------------------" << endl;
    cout <<"Indices of \"" << this_word << "\"" << endl;
    //list indices of this_word:
    if ( word_indices.contains( this_word ) )
    {
        cout << this_word << ": " << word_indices[this_word] << endl;
    }
    cout << endl << endl << endl;

    cout <<"---------------------------------------------------" << endl;
    string from = "ask";
    string to = "asker";
    //list from .. to:
    cout << "listing indices from \"" << from << "\" to \"" << to << "\"" << endl;
    cout <<"---------------------------------------------------" << endl;

    for (MMap<string, long>::Iterator it =word_indices.lower_bound(from);
         it != word_indices.upper_bound(to) &&it != word_indices.end(); it++ )
    {
        cout << *it << endl;
    }

    cout <<endl<<endl<<endl<< "========== E N D  ====================" << endl;
    return 0;
}


MMap<string, long> get_word_indices( char* file_name )
{
    const bool debug = true;
    MMap<string, long> word_indices;

    FTokenizer ftk( file_name );
    Token t;
    long count = 0;

    ftk >> t;
    while ( ftk.more( ) )
    {
        //only the "words"
        if ( t.get_type_string() == "ALPHA" )
        {
            string s;
            s = t.get_string_token( ) ;
            word_indices[s] += count;
            count++;
            if ( debug )
                 cout << "|" << t.get_string_token( ) << "|" << endl;
        }
        ftk >> t;
    }
    return word_indices;
}
