
#include <iomanip>
#include <iostream>

#include "../../!includes/Parser/parser.h"
#include "../../!includes/Table/table.h"
#include "../../!includes/SQL/sql.h"


using namespace std;


void simple_batch_test( );

void simple_parser_test( );

int main()
{

    void simple_batch_test( );

    SQL s;
    s.run( );



    cout << "=  =   =   =   =  BATCH TEST  =  =   =   =   =\n\n";

//    ifstream fin;
//    fin.open( "!sample.txt");

//    if ( fin.fail( ) )
//    {
//        cout << "Input file opening failed.\n";
//        exit(1);
//    }

//    int count = 0;

//    int i = 0;
//    while ( ! fin.eof() )
//    {
//        char s[ 200 ];
//        fin.getline( s, 150);

//        cout << s << endl;

//        Parser p(s);
//        MMap<string, string> ptree = p.get_parse_tree();

//        string table_name;

//        if ( ptree.empty() )
//            count++;

//        cout << ptree << endl << endl << endl << endl << endl;
//        i++;

//    }

//    cout <<"i: " << i << "  Fail count: " <<  count << endl << endl;
//    cout << "=  =   =   =   =  END BATCH TEST  =  =   =   =   =\n\n";




    return 0;
}


void simple_batch_test( )
{
    cout << "=  =   =   =   =  BATCH TEST  =  =   =   =   =\n\n";

    ifstream fin;
    fin.open( "!sample.txt");

    if ( fin.fail( ) )
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    int count = 0;

    int i = 0;
    while ( ! fin.eof() )
    {
        char s[ 200 ];
        fin.getline( s, 150);

        cout << s << endl;

        Parser p(s);
        MMap<string, string> ptree = p.get_parse_tree();

        string table_name;

        if ( ptree.empty() )
            count++;

        cout << ptree << endl << endl << endl << endl << endl;
        i++;

    }

    cout <<"i: " << i << "  Fail count: " <<  count << endl << endl;
    cout << "=  =   =   =   =  END BATCH TEST  =  =   =   =   =\n\n";
}

void simple_parser_test( )
{
    //    if ( p.is_valid() )
    //    {
    //        if ( ptree["command"].front() == "select")
    //            table_name = ptree["table"].front();
    //        Table t (table_name);
    //        if ( ptree.contains( "fields" ) )
    //        {
    //            if ( ptree["fields"].front() == "*" )
    //            {
    //                if ( ptree.contains( "conditions" ) )
    //                {
    //                    Table temp = t.select( ptree["conditions"] ) ;
    //                    cout << t << endl << endl;
    //                    cout << temp <<  endl << endl;
    //                    temp.drop();

    //                }
    //                else
    //                {
    //                    Table temp = t.select_all();
    //                    cout << t << endl << endl;
    //                    cout << temp <<  endl << endl;
    //                    temp.drop();

    //                }
    //            }
    //            else
    //            {
    //                Table temp = t.select(ptree["fields"]);
    //                cout << t << endl << endl;
    //                cout << temp <<  endl << endl;
    //                temp.drop();
    //            }
    //        }

    //    }
}
