//
//  AddExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//
/**
* \file AddExpr.cpp
* \brief contains AddExpr class definition
* It takes two parameters of Expr type as an input.
* It can be used for getting the result of the sum of the two input expression
* \author Author Name
*/

#include "AddExpr.hpp"
#include "Val.hpp"

/**
* \brief Constructor takes two arguments to create AddExpr object
* \param lhs first argument, Expr* type which will be the left hand side of the expression
* \param rhs second argument, Expr* type which will be the right hand side of the expression
* \return creates AddExpr type
*/
AddExpr::AddExpr(PTR(Expr) lhs, PTR(Expr) rhs) {
    this -> lhs = lhs;
    this -> rhs = rhs;
}

/**
* \brief Compares two AddExpr type expressions
* \param expr first argument, Expr type to which this AddExpr expression will be compared
* \return boolean value after comparison
*/
bool AddExpr::equals(PTR(Expr) expr) {
    PTR(AddExpr) a = CAST(AddExpr) (expr);
    
    if (a == NULL) {
        return false;
    }
    else {
        return (this->lhs->equals(a -> lhs) && this->rhs->equals(a -> rhs));
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value after calculation
*/
PTR(Val) AddExpr::interp(PTR(Env) env) {
    return lhs -> interp(env) -> add_to(rhs -> interp(env));
}

/**
* \brief Substitutes a variable present in the expression with a given expression
* \param x first argument, the variable that will be substituted
* \param exp second argument, the expression which will substitute the variable
* \return new expression after substitution
*/

void AddExpr::print(std::ostream& ot) {
    ot << "(";
    this -> lhs -> print(ot);
    ot << "+";
    this -> rhs -> print(ot);
    ot << ")";
}

std::string AddExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string AddExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void AddExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces) {
    if (precedence == prec_none || precedence == prec_let) {
        otPos = ot.tellp();
        this -> lhs -> pretty_print_at(prec_add, ot, otPos, true);
        ot << " + ";
        this -> rhs -> pretty_print_at(prec_none, ot, otPos, false);
    }
    
    if (precedence == prec_add || precedence == prec_mult) {
        otPos = ot.tellp();
        ot << "(";
        this -> lhs -> pretty_print_at(prec_add, ot, otPos, true);
        ot << " + ";
        this -> rhs -> pretty_print_at(prec_none, ot, otPos, false);
        ot << ")";
    }
}
