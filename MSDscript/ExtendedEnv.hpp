#ifndef ExtendedEnv_hpp
#define ExtendedEnv_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class ExtendedEnv : public Env {
public:
    ExtendedEnv(std::string name, PTR(Val) val, PTR(Env) rest);
    std::string name;
    PTR(Val) val;
    PTR(Env) rest;
    PTR(Val) lookup(std::string find_name);
};

#endif /* EqExpr_hpp */