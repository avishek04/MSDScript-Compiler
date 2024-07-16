//
//  IfExpr.cpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//
/**
* \file IfExpr.cpp
* \brief contains IfExpr class definition
* It takes two parameters of Expr type as an input.
* It can be used for getting the result of the sum of the two input expression
* \author Author Name
*/

#include "IfExpr.hpp"
#include "BoolVal.hpp"

/**
* \brief Constructor takes two arguments to create IfExpr object
* \param lhs first argument, Expr* type which will be the left hand side of the expression
* \param rhs second argument, Expr* type which will be the right hand side of the expression
* \return creates AddExpr type
*/
IfExpr::IfExpr(PTR(Expr) condition, PTR(Expr) trueExp, PTR(Expr) falseExp) {
    this -> condition = condition;
    this -> trueExp = trueExp;
    this -> falseExp = falseExp;
}

/**
* \brief Compares two AddExpr type expressions
* \param expr first argument, Expr type to which this AddExpr expression will be compared
* \return boolean value after comparison
*/
bool IfExpr::equals(PTR(Expr) expr) {
    PTR(IfExpr) a = CAST(IfExpr) (expr);
    
    if (a == NULL) {
        return false;
    }
    else {
        return (this->condition->equals(a -> condition) && this->trueExp->equals(a -> trueExp) && this->falseExp->equals(a -> falseExp));
    }
}

/**
* \brief Interpret the expression to an integer value
* \return integer value after calculation
*/
PTR(Val) IfExpr::interp(PTR(Env) env) {
    PTR(BoolVal) b = CAST(BoolVal) (this -> condition -> interp(env));

    if (b == NULL)
        throw std::runtime_error("If condition is not a boolean value");
    
    if (b -> is_true()) {
        return this -> trueExp -> interp(env);
    }
    else {
        return this -> falseExp -> interp(env);
    }
    // return lhs -> interp() -> add_to(rhs -> interp());
}

void IfExpr::print(std::ostream& ot) {
    ot << "(_if ";
    this -> condition -> print(ot);
    ot << " _then ";
    this -> trueExp -> print(ot);
    ot << " _else ";
    this -> falseExp -> print(ot);
    ot << ")";
}

std::string IfExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}

std::string IfExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}

void IfExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces) {
    int diff = static_cast<int>(ot.tellp()) - otPos;
    if (precedence == prec_none || precedence == prec_let) {
        ot << "_if ";
        this -> condition -> pretty_print_at(prec_none, ot, otPos, false);
        ot << "\n";
        ot << std::string(diff, ' ') << "_then ";
        this -> trueExp -> pretty_print_at(prec_none, ot, otPos, false);
        ot << "\n";
        ot << std::string(diff, ' ') << "_else ";
        this -> falseExp -> pretty_print_at(prec_none, ot, otPos, false);
    }
    
    if ((precedence == prec_add || precedence == prec_mult) && braces) {
        int diff = static_cast<int>(ot.tellp()) - otPos + 1;
        ot << "(_if ";
        this -> condition -> pretty_print_at(prec_none, ot, otPos, false);
        ot << "\n";
        ot << std::string(diff, ' ') << "_then ";
        this -> trueExp -> pretty_print_at(prec_none, ot, otPos, false);
        ot << "\n";
        ot << std::string(diff, ' ') << "_else ";
        this -> falseExp -> pretty_print_at(prec_none, ot, otPos, false);
        ot << ")";
    }
}
