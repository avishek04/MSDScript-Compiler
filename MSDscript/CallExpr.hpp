//
//  CallExpr.hpp
//  Expression
//
//  Created by Avishek Choudhury on 3/29/23.
//

#ifndef CallExpr_hpp
#define CallExpr_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class CallExpr : public Expr {
public:
    PTR(Expr) to_be_called; ///< left hand side of the CallExpr expression
    PTR(Expr) actual_arg; ///< right hand side of the CallExpr expression
    
    CallExpr(PTR(Expr) to_be_called, PTR(Expr) actual_arg);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* CallExpr_hpp */
