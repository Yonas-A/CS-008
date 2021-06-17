#include "../../!includes/Utility/util.h"

#include <iostream>
#include <string>

Util::Util() {
}

Util::Util(const std::string& s) : _input(s) {
}

std::string Util::get_value() const {
    return _input;
}

UTYPE Util::get_type() {
    return static_cast<UTYPE>(UTYPE::Word);
}

void Util::print() {
    cout << " " << _input << " ";
}

ostream& operator<<(ostream& outs, Util* U) {
    U->print();
    return outs;
}
