//
//  _let.hpp
//  Expression
//
//  Created by Avishek Choudhury on 2/13/23.
//

#ifndef _let_hpp
#define _let_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class VariableExpr;

class _letExpr : public Expr {
public:
    std::string var;
    PTR(Expr) rhs;
    PTR(Expr) body;
    
    _letExpr(std::string var, PTR(Expr) rhs, PTR(Expr) body);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* _let_hpp */
