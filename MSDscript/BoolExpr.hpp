//
//  BoolExpr.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file Expr.hpp
* \brief Expr class
**
Holds the signature for all the methods of the Num class
*/

#ifndef BoolExpr_hpp
#define BoolExpr_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class BoolExpr : public Expr {
public:
    bool rep; ///< integer value that represent the value of the Num expression
    
    BoolExpr(bool rep);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* Num_hpp */
