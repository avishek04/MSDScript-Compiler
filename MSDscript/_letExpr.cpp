//
//  _letExpr.cpp
//  Expression
//
//  Created by Avishek Choudhury on 2/13/23.
//

#include "_letExpr.hpp"
#include "Val.hpp"
#include "ExtendedEnv.hpp"

_letExpr::_letExpr(std::string var, PTR(Expr) rhs, PTR(Expr) body) {
    this -> var = var;
    this -> rhs = rhs;
    this -> body = body;
}
    
bool _letExpr::equals(PTR(Expr) expr) {
    PTR(_letExpr) l = CAST(_letExpr)(expr);
    
    if (l == NULL) {
        return false;
    }
    else {
        return (this->var == l -> var && this->rhs->equals(l -> rhs) && this->body->equals(l -> body));
    }
}

PTR(Val) _letExpr::interp(PTR(Env) env) {
    PTR(Val) rhsVal = this->rhs->interp(env);
    return this->body->interp(NEW(ExtendedEnv) (this->var, rhsVal, env));
}
    
void _letExpr::print(std::ostream &ot) {
    ot << "(_let " << this->var << "=";
    this->rhs->print(ot);
    ot << " _in ";
    this->body->print(ot);
    ot << ")";
}
    
std::string _letExpr::to_string() {
    std::stringstream st("");
    this->print(st);
    return st.str();
}
    
std::string _letExpr::to_prettyString() {
    std::stringstream st("");
    this->pretty_print(st);
    return st.str();
}
    
void _letExpr::pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces = false) {
    // int diff = static_cast<int>(ot.tellp()) - otPos;
    if (braces) {
        ot << "(";
    }
    
    if (precedence == prec_let || precedence == prec_add || precedence == prec_mult) {
        int diff = static_cast<int>(ot.tellp()) - otPos;
        ot << "_let " << this->var << " = ";
        this -> rhs -> pretty_print_at(prec_let, ot, otPos, false);
        ot << "\n";
        ot << std::string(diff, ' ') << "_in  ";
        this -> body -> pretty_print_at(prec_let, ot, otPos, false);
    }
    else {
        int diff = static_cast<int>(ot.tellp()) - otPos;
        ot << "_let " << this -> var << " = ";
        this -> rhs -> pretty_print_at(prec_let, ot, otPos, false);
        ot << "\n";
        // otPos = ot.tellp();
        ot << std::string(diff, ' ') << "_in  ";
        this -> body -> pretty_print_at(prec_let, ot, otPos, false);
    }
    if (braces) {
        ot << ")";
    }
}
