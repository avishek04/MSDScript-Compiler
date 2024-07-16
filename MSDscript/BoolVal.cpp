//
//  NumVal.cpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#include "BoolVal.hpp"
#include "BoolExpr.hpp"

BoolVal::BoolVal(bool rep) {
    this -> rep = rep;
}

PTR(Val) BoolVal::add_to(PTR(Val) other_val) {
    throw std::runtime_error("add of boolean values is not possible");
}

PTR(Val) BoolVal::mult_with(PTR(Val) other_val) {
    throw std::runtime_error("mult of boolean values is not possible");
}

PTR(Val) BoolVal::call(PTR(Val) actual_arg) {
    throw std::runtime_error("this is not a function");
}

bool BoolVal::equals(PTR(Val) other_val) {
    PTR(BoolVal) other_bool = CAST(BoolVal) (other_val);
    
    if (other_bool == NULL)
        return false;
        // throw std::runtime_error("equality of non-boolean");
    
    return (this->rep == other_bool->rep);
}

bool BoolVal::is_true() {
    return this -> rep;
}

std::string BoolVal::to_string() {
    return (this -> rep ? "_true" : "_false");
}
