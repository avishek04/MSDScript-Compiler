//
//  AddExpr.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file AddExpr.hpp
* \brief AddExpr class
**
Holds the signature of all the methods present in the AddExpr class
*/

#ifndef Add_hpp
#define Add_hpp

#include <stdio.h>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class AddExpr : public Expr {
public:
    PTR(Expr) lhs; ///< left hand side of the AddExpr expression
    PTR(Expr) rhs; ///< right hand side of the AddExpr expression
    
    AddExpr(PTR(Expr) lhs, PTR(Expr) rhs);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* Add_hpp */
