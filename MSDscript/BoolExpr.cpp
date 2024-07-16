//
//  BoolExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file BoolExpr.cpp
* \brief contains BoolExpr class definition
* It takes one parameter of type int as an input.
* It can be used for creating an object of type BoolExpr which has the integer value.
* \author Avishek
*/
#include "BoolExpr.hpp"
#include "BoolVal.hpp"

/**
* \brief Constructor takes one argument to create NumExpr object
* \param int first argument, int type which will be set as the value for rep.
* \return creates Add type
*/
BoolExpr::BoolExpr(bool rep) {
    this -> rep = rep;
}

/**
* \brief Compares two NumExpr type expressions
* \param expr first argument, Expr type to which this NumExpr expression will be compared
* \return boolean value after comparison
*/
bool BoolExpr::equals(PTR(Expr) expr) {
    PTR(BoolExpr) n = CAST(BoolExpr) (expr);
    
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
PTR(Val) BoolExpr::interp(PTR(Env) env) {
    return NEW(BoolVal) (this->rep);
}

/**
* \brief checks if the expression has a variable
* \return always returns boolean value as the expression is an integer
*/
//bool BoolExpr::has_variable() {
//    return false;
//}

void BoolExpr::print(std::ostream &ot) {
    ot << (this -> rep ? "_true" : "_false");
}

std::string BoolExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string BoolExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void BoolExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces = false) {
    ot << (this -> rep ? "_true" : "_false");
}
