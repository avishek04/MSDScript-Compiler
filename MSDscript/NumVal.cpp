//
//  NumVal.cpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#include "NumVal.hpp"
#include "NumExpr.hpp"
#include <limits.h>

NumVal::NumVal(long rep) {
    if (rep > INT_MAX || rep < INT_MIN) {
        throw std::runtime_error("Number overflow");
    }
    this -> rep = rep;
}

PTR(Val) NumVal::add_to(PTR(Val) other_val) {
    PTR(NumVal) other_num = CAST(NumVal) (other_val);

    if (other_num == NULL)
        throw std::runtime_error("add of non-number");

    long addNum = (long)(this -> rep) + (long)(other_num -> rep);
    if (addNum > INT_MAX || addNum < INT_MIN) {
        throw std::runtime_error("Addition caused number overflow");
    }
    
    return NEW(NumVal) (addNum);
}

PTR(Val) NumVal::mult_with(PTR(Val) other_val) {
    PTR(NumVal) other_num = CAST(NumVal) (other_val);
    
    if (other_num == NULL)
        throw std::runtime_error("mult of non-number");
    
    long multNum = (long)(this -> rep) * (long)(other_num -> rep);
    if (multNum > INT_MAX || multNum < INT_MIN) {
        throw std::runtime_error("Multiplication caused number overflow");
    }

    return NEW(NumVal) (multNum);
}

PTR(Val) NumVal::call(PTR(Val) actual_arg) {
    throw std::runtime_error("This is not a function");
}

bool NumVal::equals(PTR(Val) other_val) {
    PTR(NumVal) other_num = CAST(NumVal) (other_val);
    
    if (other_num == NULL)
        return false;
        // throw std::runtime_error("equality of non-number");
    
    if (this->rep == other_num-> rep)
        return true;
    
    return false;
}

bool NumVal::is_true() {
    throw std::runtime_error("object is a number");
}

std::string NumVal::to_string() {
    return std::to_string(this->rep);
}
