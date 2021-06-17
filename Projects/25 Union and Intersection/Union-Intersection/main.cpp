#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

#include "../../!includes/Union_n_Intesection/intersection_and_union.h"


using namespace std;


static const int high = 100;
static const int low = 0;

void array_test();

void vector_test();


void union_check( const vector<int>& v1, const vector<int>& v2,
                  vector<int>* vec)
{
    Map<int, int> m1;
}

void check_intersection(const vector<int>& v1, const vector<int>& v2,
                        vector<int>* vec)
{
    Map<int, int> m1;
    Map<int, int> m2;
    fill_map( m1, v1 );
    fill_map( m2, v2 );

    int count = 0;
    for ( size_t i = 0; i < vec->size( ); i++ )
    {
        int temp = vec->at( i );

        if ( m1.contains(temp ) && m2.contains( temp ) )
        {
        }
        else
        {
            count++;
        }

    }


    if ( count > 0 )
        cout << "*********INTERSECTION FAILED:***********" << endl;
    else
        cout << "*********INTERSECTION SUCCESS:***********" << endl;
}



int main()
{
    srand( time( nullptr ) ) ;


//    array_test();

    vector_test( );

    return 0;
}

void array_test()
{
    cout << "=   =   =   =   =  ARRAY TEST  =   =   =   =   =" << endl << endl;
    int src[ high ] ;
    int arr[ high];
    int* finalArr;
    int size = 0;

    for ( int i = 0; i < high ; i++ )
    {
        src[ i ] = rand() % ( high - low + 1) + low;
        arr[ i] = rand() % ( high - low + 1) + low;
    }
    print( src , high );
    print( arr , high );


    cout << "=   =   =   =   =   =   =   INTERSECTIONS  =   =   =   =   =   =   =" << endl << endl;

    finalArr = Intersection ( src, high,  arr, high, size);
    print ( finalArr, size );
    // ============================================================
    /// testing union

    cout << "=   =   =   =   =   =   =   =  UNION   =   =   =   =   =   =   =   =" << endl << endl;

    finalArr = Union ( src, high,  arr, high, size);
    print ( finalArr, size );

}

void vector_test()
{
    cout << "=   =   =   =   = VECTOR TEST =   =   =   =   =" << endl << endl;

    vector<int> src;
    vector<int> vec;
    for ( int i = 0; i < high ; i++ )
    {
        src.push_back( rand() % ( high - low + 1) + low );
        vec.push_back( rand() % ( high - low + 1) + low );
    }

        cout << "=   =   =   =   =   =   =   =  UNION   =   =   =   =   =   =   =   =" << endl << endl;
    vector<int>* finalvec;
    finalvec = Union( src, vec );
    print( finalvec );


    cout << "=   =   =   =   =   =   =   INTERSECTIONS  =   =   =   =   =   =   =" << endl << endl;
    vector<int>* intersectionVec;
    intersectionVec = Intersection( src, vec );
    print( intersectionVec );

   check_intersection( src, vec, intersectionVec );


}
