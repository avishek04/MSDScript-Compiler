//
//  Value.hpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#ifndef Val_hpp
#define Val_hpp

#include <string>
#include "pointer.hpp"
#include "Expr.hpp"

//CLASS(Expr);
class Expr;

CLASS(Val) {
public:
    virtual ~Val() { };
    virtual PTR(Val) add_to(PTR(Val) other_val) = 0;
    virtual PTR(Val) mult_with(PTR(Val) other_val) = 0;
    virtual PTR(Val) call(PTR(Val) actual_arg) = 0;
    virtual bool equals(PTR(Val) other_val) = 0;
    virtual bool is_true() = 0;
    virtual std::string to_string() = 0;
};

#endif /* Val_hpp */
