#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <vector>

using namespace std;

// initializes numbers
const string NUM = "0123456789.";
// initializes operators
const string OP =
    "><=>&&||orOrORoR"
    "andAndAND";
const vector<string> OPERATORS = {">=", ">", "<", "<=", "==", "=",
                                  "||", "&&", "or", "OR", "oR", "Or",
                                  "and", "And", "AND"};
// initializes left parenthesis
const string LEFTP = "(";
// initializes right parenthesis
const string RIGHTP = ")";
const string WORD =
    "abcdefghijklmnopqrstuvwxyz\""
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#endif  // CONSTANTS_H
