#include "../../!includes/Utility/utilrecord.h"

#include "../../!includes/Utility/util.h"

// =========================================================
// ctor's

/// sets _var  to s, also instantiates parent class Token
UtilRecord::UtilRecord(const vector<long>& s) : _vec(s) {
}

vector<long> UtilRecord::get_value() const {
    return _vec;
}

UTYPE UtilRecord::get_type() {
    return static_cast<UTYPE>(UTYPE::LogicalOperator);
    /// \return  value of UTYPE enum from
}

// =========================================================
// display

void UtilRecord::print() {
    for (size_t i = 0; i < _vec.size(); i++) {
        cout << _vec[i] << " ";
    }
}
