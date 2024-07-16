//
//  IfExpr.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file IfExpr.hpp
* \brief IfExpr class
**
Holds the signature for all the methods of the Num class
*/

#ifndef IfExpr_hpp
#define IfExpr_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class IfExpr : public Expr {
public:
    PTR(Expr) condition;
    PTR(Expr) trueExp;
    PTR(Expr) falseExp;
    
    IfExpr(PTR(Expr) condition, PTR(Expr) trueExp, PTR(Expr) falseExp);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* Num_hpp */
