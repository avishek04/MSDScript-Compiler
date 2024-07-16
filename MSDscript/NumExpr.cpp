//
//  NumExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file NumExpr.cpp
* \brief contains NumExpr class definition
* It takes one parameter of type int as an input.
* It can be used for creating an object of type NumExpr which has the integer value.
* \author Avishek
*/
#include "NumExpr.hpp"
#include "NumVal.hpp"
#include <limits.h>

/**
* \brief Constructor takes one argument to create NumExpr object
* \param int first argument, int type which will be set as the value for rep.
* \return creates Add type
*/
NumExpr::NumExpr(long rep) {
    if (rep > INT_MAX || rep < INT_MIN) {
        throw std::runtime_error("Number overflow");
    }
    this -> rep = rep;
}

/**
* \brief Compares two NumExpr type expressions
* \param expr first argument, Expr type to which this NumExpr expression will be compared
* \return boolean value after comparison
*/
bool NumExpr::equals(PTR(Expr) expr) {
    PTR(NumExpr) n = CAST(NumExpr) (expr);
    
    if (n == NULL) {
        return false;
    }
    else {
        return (this -> rep == n -> rep);
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value
*/
PTR(Val) NumExpr::interp(PTR(Env) env) {
    return NEW(NumVal) (this->rep);
}

void NumExpr::print(std::ostream &ot) {
    ot << std::to_string(rep);
}

std::string NumExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string NumExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void NumExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces = false) {
    ot << std::to_string(rep);
}
