//
//  MultExpr.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file Expr.hpp
* \brief Expr class
**
Holds the signature for all the methods of the MultExpr class
*/
#ifndef Mult_hpp
#define Mult_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class MultExpr : public Expr {
public:
    PTR(Expr) lhs; ///< left hand side of the MultExpr expression
    PTR(Expr) rhs; ///< right hand side of the MultExpr expression
    
    MultExpr(PTR(Expr) lhs, PTR(Expr) rhs);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* Mult_hpp */
