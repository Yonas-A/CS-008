#ifndef UNION_H
#define UNION_H
#include <iostream>

using namespace std;

const int MAX1 = 10;
const int MAX2 = 10;
const int RESULT_MAX = 20;

template <typename T>
vector<T>* Intersection(const std::vector<T>& v1, const vector<T>& v2);


template <typename T>
vector<T>* Union( const std::vector<T>& v1, const std::vector<T>& v2);


void print( int arr[], int size);


int* Intersection( int *src1, int s1, int* src2, int s2, int* arr );

int* Union( int* src1, int size1, int* src2, int size2, int& union_size);

// =================================================================



//template <typename T>
//vector<T>* Union( const std::vector<T>& v1, const std::vector<T>& v2)
//{
//    T* p1 = v1;
//    T* p2 = v2;
//    vector<T> temp;
//    T* temp = union_ptr;
//    while (( p1 != ( ptr1 + size1)) && ((src2 != (ptr2 + size2))))
//    {
//        if(*src1 > *src2)
//        {
//            //when src1 element bigger than src2 element
//            *union_ptr = *src2;
//            src2++;
//            union_size++;
//        }

//        else if( *src2 > *src1)
//        {
//            //when src1 element bigger than src2 element
//            *union_ptr = *src1;
//            src1++;
//            union_size++;
//        }

//        else
//        {
//            //when src1 element equal to src2 element
//            *union_ptr = *src1;
//            src1++;
//            src2++;
//            union_size++;
//        }
//        union_ptr++;
//    }

//    if ((src1 == (ptr1 + size1)) && (src2 < (ptr2 + size2) ))
//    { //when src1 elements are copied but src2 has some left
//        while (src2 < (ptr2 + size2))
//        {
//            *union_ptr = *src2;
//            src2++;
//            union_ptr++;
//            union_size++;

//        }
//    }

//    if (( src2 == ( ptr2 + size2)) && (src1 < ( ptr1 + size1) ))
//    {
//        //when src2 elements are copied but src1 has some left
//        while (src1 < ( ptr1 + size1))
//        {
//            *union_ptr = *src1;
//            src1++;
//            union_ptr++;
//            union_size++;
//        }
//    }

//}

int* Union( int* src1, int size1, int* src2, int size2, int& union_size)
{
    int* ptr1 = src1;
    int* ptr2 = src2;
    int* union_ptr = nullptr;
    union_ptr = new int[size1 + size2 ];
    int* temp = union_ptr;

    while ((src1 != (ptr1 + size1)) && ((src2 != (ptr2 + size2))))
    {
        if(*src1 > *src2)
        {
            //when src1 element bigger than src2 element
            *union_ptr = *src2;
            src2++;
            union_size++;
        }

        else if( *src2 > *src1)
        {
            //when src1 element bigger than src2 element
            *union_ptr = *src1;
            src1++;
            union_size++;
        }

        else
        {
            //when src1 element equal to src2 element
            *union_ptr = *src1;
            src1++;
            src2++;
            union_size++;
        }
        union_ptr++;
    }

    if ((src1 == (ptr1 + size1)) && (src2 < (ptr2 + size2) ))
    { //when src1 elements are copied but src2 has some left
        while (src2 < (ptr2 + size2))
        {
            *union_ptr = *src2;
            src2++;
            union_ptr++;
            union_size++;

        }
    }

    if (( src2 == ( ptr2 + size2)) && (src1 < ( ptr1 + size1) ))
    {
        //when src2 elements are copied but src1 has some left
        while (src1 < ( ptr1 + size1))
        {
            *union_ptr = *src1;
            src1++;
            union_ptr++;
            union_size++;
        }
    }

    return temp;

}



void print(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    cout << "\t\t [" << size << "]" << endl << endl;

}

#endif // UNION_H

