//
//  Variable.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file Variable.hpp
* \brief Variable class
**
Holds the signature for all the methods of the Variable class
*/

#ifndef Variable_hpp
#define Variable_hpp

#include <stdio.h>
#include <string>
#include "Expr.hpp"
#include "pointer.hpp"
#include "Env.hpp"

class VariableExpr : public Expr {
public:
    std::string var; ///< variable which represents the expression of the Variable class
    
    VariableExpr(std::string var);
    bool equals(PTR(Expr) expr);
    PTR(Val) interp(PTR(Env) env);
    void print(std::ostream &ot);
    std::string to_string();
    std::string to_prettyString();
    void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces);
};

#endif /* Variable_hpp */
