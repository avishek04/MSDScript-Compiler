//
//  VariableExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file VariableExpr.cpp
* \brief contains VariableExpr class definition
* It takes one parameter of type string as an input.
* It can be used for creating an object of type VariableExpr which stores string as it's value.
* \author Avishek
*/

#include "VariableExpr.hpp"
#include "Val.hpp"

/**
* \brief Constructor takes one argument to create Mult object
* \param var first argument, string type which will be the argument
* \return VariableExpr type
*/
VariableExpr::VariableExpr(std::string var) {
    this -> var = var;
}

/**
* \brief Compares two VariableExpr type expressions
* \param expr first argument, Expr type to which this VariableExpr expression will be compared
* \return boolean value after comparison
*/
bool VariableExpr::equals(PTR(Expr) expr) {
    PTR(VariableExpr) v = CAST(VariableExpr) (expr);
    if (v == NULL) {
        return false;
    }
    else {
        return (this -> var == v -> var);
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value after calculation, in this case error
*/
PTR(Val) VariableExpr::interp(PTR(Env) env) {
    return env -> lookup(this -> var);
    // throw std::runtime_error("no value for a VariableExpr");
}

void VariableExpr::print(std::ostream& ot) {
    ot << this -> var;
}

std::string VariableExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string VariableExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void VariableExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces) {
    ot << this -> var;
}
