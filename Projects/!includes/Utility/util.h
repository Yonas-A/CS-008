#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>

enum class UTYPE : int { Word = 0,
                         LogicalOperator = 1 };

using namespace std;

class Util {
   public:
    /**
     * @brief a  constructor that'll set Util::_input to an empty string
     */
    Util();

    /**
     * @brief a constructor that'll set private member variable _input to string s
     * @param s a string variable 
     */
    Util(const std::string& s);

    /**
     * \returns the value of mem var Util::_input
     */
    std::string get_value() const;

    ///
    /**
     * @brief a virtual function that'll return the type of token Util::_input is
     */
    virtual UTYPE get_type();

    /**
     * @brief  a virtual function that'll print current token
     */
    virtual void print();

    /**
     * @brief a friend insertion operator that'll print  Util::U's mem var _input
     */
    friend ostream& operator<<(ostream& outs, Util* U);

   private:
    /// a string that'll hold a string which will be tokenized
    std::string _input;
};

#endif  // UTIL_H
