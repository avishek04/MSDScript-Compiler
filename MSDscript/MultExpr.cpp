//
//  MultExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file MultExpr.cpp
* \brief contains MultExpr class definition
* It takes two parameters of Expr type as an input.
* It can be used for getting the result of the multiplication of the two input expression
* \author Avishek
*/
#include "MultExpr.hpp"
#include "NumVal.hpp"

/**
* \brief Constructor takes two arguments to create MultExpr object
* \param lhs first argument, Expr* type which will be the left hand side of the expression
* \param rhs second argument, Expr* type which will be the right hand side of the expression
* \return creates MultExpr type
*/
MultExpr::MultExpr(PTR(Expr) lhs, PTR(Expr) rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

/**
* \brief Compares two MultExpr type expressions
* \param expr first argument, Expr type to which this MultExpr expression will be compared
* \return boolean value after comparison
*/
bool MultExpr::equals(PTR(Expr) expr) {
    PTR(MultExpr) m = CAST(MultExpr) (expr);
    
    if (m == NULL) {
        return false;
    }
    else {
        return (this->lhs->equals(m -> lhs) && this->rhs->equals(m -> rhs));
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value after calculation
*/
PTR(Val) MultExpr::interp(PTR(Env) env) {
    return lhs -> interp(env) -> mult_with(rhs -> interp(env));
}

void MultExpr::print(std::ostream& ot) {
    ot << "(";
    this -> lhs -> print(ot);
    ot << "*";
    this -> rhs -> print(ot);
    ot << ")";
}

std::string MultExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string MultExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void MultExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces = false) {
    if (precedence == prec_mult) {
        otPos = ot.tellp();
        ot << "(";
        this -> lhs -> pretty_print_at(prec_mult, ot, otPos, true);
        ot << " * ";
        this -> rhs -> pretty_print_at(prec_mult, ot, otPos, false);
        ot << ")";
    }
    else {
        otPos = ot.tellp();
        this -> lhs -> pretty_print_at(prec_mult, ot, otPos, true);
        ot << " * ";
        if (precedence == prec_add) {
            this -> rhs -> pretty_print_at(prec_add, ot, otPos, true);
        }
        else {
            this -> rhs -> pretty_print_at(prec_add, ot, otPos, false);
        }
    }
}
