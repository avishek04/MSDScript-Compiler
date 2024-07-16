//
//  FunExpr.hpp
//  Expression
//
//  Created by Avishek Choudhury on 3/29/23.
//

#ifndef FunExpr_hpp
#define FunExpr_hpp

#include <stdio.h>
#include "Expr.hpp"
#include <string>
#include "pointer.hpp"
#include "Env.hpp"

class FunExpr : public Expr {
public:
    std::string formal_arg; ///< left hand side of the FunExpr expression
    PTR(Expr) body; ///< right hand side of the FunExpr expression
    
    FunExpr(std::string formal_arg, PTR(Expr) body);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* FunExpr_hpp */
