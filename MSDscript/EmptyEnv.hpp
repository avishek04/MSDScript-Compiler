#ifndef EmptyEnv_hpp
#define EmptyEnv_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class EmptyEnv : public Env {
public:
    PTR(Val) lookup(std::string find_name);
};

#endif /* EqExpr_hpp */