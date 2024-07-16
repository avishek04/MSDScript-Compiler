//
//  EqExpr.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file EqExpr.hpp
* \brief EqExpr class
**
Holds the signature of all the methods present in the EqExpr class
*/

#ifndef EqExpr_hpp
#define EqExpr_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class EqExpr : public Expr {
public:
    PTR(Expr) lhs; ///< left hand side of the AddExpr expression
    PTR(Expr) rhs; ///< right hand side of the AddExpr expression
    
    EqExpr(PTR(Expr) lhs, PTR(Expr) rhs);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* EqExpr_hpp */
