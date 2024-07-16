//
//  FunExpr.cpp
//  Expression
//
//  Created by Avishek Choudhury on 3/29/23.
//

/**
* \file FunExpr.cpp
* \brief contains FunExpr class definition
* It takes two parameters of Expr type as an input.
* It can be used for getting the result of the sum of the two input expression
* \author Author Name
*/

#include "FunExpr.hpp"
#include "FunVal.hpp"

/**
* \brief Constructor takes two arguments to create FunExpr object
* \param lhs first argument, Expr* type which will be the left hand side of the expression
* \param rhs second argument, Expr* type which will be the right hand side of the expression
* \return creates FunExpr type
*/
FunExpr::FunExpr(std::string formal_arg, PTR(Expr) body) {
    this -> formal_arg = formal_arg;
    this -> body = body;
}

/**
* \brief Compares two FunExpr type expressions
* \param expr first argument, Expr type to which this CallExpr expression will be compared
* \return boolean value after comparison
*/
bool FunExpr::equals(PTR(Expr) expr) {
    PTR(FunExpr) a = CAST(FunExpr) (expr);
    
    if (a == NULL) {
        return false;
    }
    else {
        return (this->formal_arg == a -> formal_arg && this->body->equals(a -> body));
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value after calculation
*/
PTR(Val) FunExpr::interp(PTR(Env) env) {
    return NEW(FunVal) (this -> formal_arg, this -> body, env);
}

void FunExpr::print(std::ostream& ot) {
    ot << "(_fun (" << this -> formal_arg << ") ";
    this -> body -> print(ot);
    ot << ")";
}

std::string FunExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string FunExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void FunExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces) {
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
