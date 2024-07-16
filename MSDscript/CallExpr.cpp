//
//  CallExpr.cpp
//  Expression
//
//  Created by Avishek Choudhury on 3/29/23.
//

/**
* \file CallExpr.cpp
* \brief contains CallExpr class definition
* It takes two parameters of Expr type as an input.
* It can be used for getting the result of the sum of the two input expression
* \author Author Name
*/

#include "CallExpr.hpp"
#include "Val.hpp"

/**
* \brief Constructor takes two arguments to create CallExpr object
* \param lhs first argument, Expr* type which will be the left hand side of the expression
* \param rhs second argument, Expr* type which will be the right hand side of the expression
* \return creates CallExpr type
*/
CallExpr::CallExpr(PTR(Expr) to_be_called, PTR(Expr) actual_arg) {
    this -> to_be_called = to_be_called;
    this -> actual_arg = actual_arg;
}

/**
* \brief Compares two CallExpr type expressions
* \param expr first argument, Expr type to which this CallExpr expression will be compared
* \return boolean value after comparison
*/
bool CallExpr::equals(PTR(Expr) expr) {
    PTR(CallExpr) a = CAST(CallExpr) (expr);
    
    if (a == NULL) {
        return false;
    }
    else {
        return (this->to_be_called->equals(a -> to_be_called) && this->actual_arg->equals(a -> actual_arg));
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value after calculation
*/
PTR(Val) CallExpr::interp(PTR(Env) env) {
    return this -> to_be_called -> interp(env) -> call(actual_arg -> interp(env));
}

void CallExpr::print(std::ostream& ot) {
    this -> to_be_called -> print(ot);
    ot << " (";
    this -> actual_arg -> print(ot);
    ot << ") ";
}

std::string CallExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string CallExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void CallExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces) {
//    if (precedence == prec_none || precedence == prec_let) {
//        otPos = ot.tellp();
//        this -> lhs -> pretty_print_at(prec_add, ot, otPos, true);
//        ot << " + ";
//        this -> rhs -> pretty_print_at(prec_none, ot, otPos, false);
//    }
//    
//    if (precedence == prec_add || precedence == prec_mult) {
//        otPos = ot.tellp();
//        ot << "(";
//        this -> lhs -> pretty_print_at(prec_add, ot, otPos, true);
//        ot << " + ";
//        this -> rhs -> pretty_print_at(prec_none, ot, otPos, false);
//        ot << ")";
//    }
}
