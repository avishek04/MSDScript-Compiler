//
//  AddExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//
/**
* \file EqExpr.cpp
* \brief contains EqExpr class definition
* It takes two parameters of Expr type as an input.
* It can be used for getting the result of the sum of the two input expression
* \author Author Name
*/

#include "EqExpr.hpp"
#include "Val.hpp"
#include "BoolVal.hpp"

/**
* \brief Constructor takes two arguments to create EqExpr object
* \param lhs first argument, Expr* type which will be the left hand side of the expression
* \param rhs second argument, Expr* type which will be the right hand side of the expression
* \return creates EqExpr type
*/
EqExpr::EqExpr(PTR(Expr) lhs, PTR(Expr) rhs) {
    this -> lhs = lhs;
    this -> rhs = rhs;
}

/**
* \brief Compares two EqExpr type expressions
* \param expr first argument, Expr type to which this EqExpr expression will be compared
* \return boolean value after comparison
*/
bool EqExpr::equals(PTR(Expr) expr) {
    PTR(EqExpr) a = CAST(EqExpr) (expr);
    
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
PTR(Val) EqExpr::interp(PTR(Env) env) {
    return NEW(BoolVal) (lhs -> interp(env) -> equals(rhs -> interp(env)));
}

void EqExpr::print(std::ostream& ot) {
    ot << "(";
    this -> lhs -> print(ot);
    ot << "==";
    this -> rhs -> print(ot);
    ot << ")";
}

std::string EqExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string EqExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void EqExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces) {
    if (precedence == prec_none || precedence == prec_let) {
        this -> lhs -> print(ot);
        ot << "==";
        this -> rhs -> print(ot);
    }

    if (precedence == prec_add || precedence == prec_mult) {
        ot << "(";
        this -> lhs -> print(ot);
        ot << "==";
        this -> rhs -> print(ot);
        ot << ")";
    }
    
    // if (precedence == prec_none || precedence == prec_let) {
    //     this -> lhs -> pretty_print_at(prec_add, ot, otPos, true);
    //     ot << " + ";
    //     this -> rhs -> pretty_print_at(prec_none, ot, otPos, false);
    // }
    
    // if (precedence == prec_add || precedence == prec_mult) {
    //     ot << "(";
    //     this -> lhs -> pretty_print_at(prec_add, ot, otPos, true);
    //     ot << " + ";
    //     this -> rhs -> pretty_print_at(prec_none, ot, otPos, false);
    //     ot << ")";
    // }
}
