//
//  FunVal.hpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#ifndef FunVal_hpp
#define FunVal_hpp

#include "Val.hpp"
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class FunVal : public Val {
public:
    std::string formal_arg;
    PTR(Expr) body;
    PTR(Env) env; 
    FunVal(std::string formal_arg, PTR(Expr) body, PTR(Env) env);
    PTR(Val) add_to(PTR(Val) other_val);
    PTR(Val) mult_with(PTR(Val) other_val);
    PTR(Val) call(PTR(Val) actual_arg);
    bool equals(PTR(Val) other_val);
    bool is_true();
    PTR(Expr) to_expr();
    std::string to_string();
};

#endif /* FunVal_hpp */
