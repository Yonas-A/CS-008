#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

#include <iostream>

/// \details all the enumerations for the state machine and every enumeration used for the database project
///

enum class KEYWORDS:int
            { SELECT = 1, STAR = 2, FROM = 3, MAKE = 4,
              CREATE = 5, BATCH = 6, WHERE = 7, UPDATE = 8,
              DELETE = 9, INSERT = 10, DROP = 11, INTO = 12,
              TABLE = 13, FIELDS = 14, SYMBOL = 15  };
enum class error:int
            { create = 0,   drop = 1,  _delete = 2,
              insert = 3,   make = 4,  select = 5 ,
              _default = 6,   };
enum class success:int
            { create = 0,   drop = 1,  _delete = 2,
              insert = 3,   make = 4,  select = 5 ,
               _default = 6,   };

// inline std::ostream& operator<<(std::ostream& outs, const success& s);

// inline std::ostream& operator<<(std::ostream& outs, const error& e);


/// writes to the screen success massage based on the success state of s
inline std::ostream& operator<<(std::ostream& outs, const success& s) {
    switch (static_cast<success>(s)) {
        case success::create:
            outs << "SQL: create: done:: " << std::endl
                 << std::endl;
            break;
        case success::drop:
            outs << "SQL: drop: done:: " << std::endl
                 << std::endl;
            break;
        case success::_delete:
            outs << "SQL: delete: done:: " << std::endl
                 << std::endl;
            break;
        case success::insert:
            outs << "SQL: insert: done:: " << std::endl
                 << std::endl;
            break;
        case success::make:
            outs << "SQL: make: done:: " << std::endl
                 << std::endl;
            break;
        case success::select:
            outs << "SQL: select: done:: " << std::endl
                 << std::endl;
            break;
        case success::_default:
        default:
            outs << "SQL: done: " << std::endl
                 << std::endl;
            ;
            break;
    }
    return outs;
}

/// writes to the screen error massage based on the error state of e
inline std::ostream& operator<<(std::ostream& outs, const error& e) {
    outs << "***ERROR***: ";
    switch (static_cast<error>(e)) {
        case error::create:
            outs << "create: table name already exists" << std::endl
                 << std::endl;
            break;
        case error::drop:
            outs << "drop: table name does not exist" << std::endl
                 << std::endl;
            break;
        case error::_delete:
            outs << "delete: table name does not exist" << std::endl
                 << std::endl;
            break;
        case error::insert:
            outs << "insert: table name does not exist" << std::endl
                 << std::endl;
            ;
            break;
        case error::make:
            outs << "make: table name already exists" << std::endl
                 << std::endl;
            break;
        case error::select:
            outs << "select: table name does not exist" << std::endl
                 << std::endl;
            break;
        case error::_default:
        default:
            outs << "command INVALID: " << std::endl
                 << std::endl;
            ;
            break;
    }
    return outs;
}


#endif  // ENUMERATIONS_H
