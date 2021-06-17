#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <vector>

using namespace  std;


const string NUM = "0123456789.";       // initializes numbers
const string OP = "><=>&&||orOrORoR"
                  "andAndAND";                   // initializes operators
const vector<string> OPERATORS = { ">=", ">", "<", "<=", "==", "=",
                                   "||", "&&" , "or", "OR","oR", "Or",
                                   "and", "And", "AND" };
const string LEFTP = "(";               // initializes left parenthesis
const string RIGHTP = ")";              // initializes right parenthesis
const string WORD = "abcdefghijklmnopqrstuvwxyz\""
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



#endif // CONSTANTS_H


