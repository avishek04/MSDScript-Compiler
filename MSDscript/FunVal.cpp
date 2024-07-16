//
//  FunVal.cpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#include "FunVal.hpp"
#include "FunExpr.hpp"
#include "ExtendedEnv.hpp"

FunVal::FunVal(std::string formal_arg, PTR(Expr) body, PTR(Env) env) {
    this -> formal_arg = formal_arg;
    this -> body = body;
    this -> env = env;
}

PTR(Val) FunVal::add_to(PTR(Val) other_val) {
    throw std::runtime_error("This is not a number, this is a function");
}

PTR(Val) FunVal::mult_with(PTR(Val) other_val) {
    throw std::runtime_error("This is not a number, this is a function");
}

PTR(Val) FunVal::call(PTR(Val) actual_arg) {
    return this -> body -> interp(NEW(ExtendedEnv) (this -> formal_arg, actual_arg, this->env));
}

bool FunVal::equals(PTR(Val) other_val) {
    PTR(FunVal) other_fun = CAST(FunVal) (other_val);
    
    if (other_fun == NULL)
        throw std::runtime_error("equality of non-function");
    
    if (this->formal_arg == other_fun -> formal_arg && this -> body == other_fun -> body)
        return true;
    
    return false;
}

bool FunVal::is_true() {
    throw std::runtime_error("object is a function");
}

PTR(Expr) FunVal::to_expr() {
    return NEW(FunExpr) (this->formal_arg, this->body);
}

std::string FunVal::to_string() {
//    return std::to_string(this->rep);
    return "_fun (" + this -> formal_arg + ") " + this -> body -> to_string();
}
