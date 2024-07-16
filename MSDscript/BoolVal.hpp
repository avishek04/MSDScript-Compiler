//
//  NumVal.hpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#ifndef BoolVal_hpp
#define BoolVal_hpp

#include "Val.hpp"
#include "Expr.hpp"
#include "pointer.hpp"

class BoolVal : public Val {
public:
    bool rep;
    BoolVal(bool rep);
    PTR(Val) add_to(PTR(Val) other_val);
    PTR(Val) mult_with(PTR(Val) other_val);
    PTR(Val) call(PTR(Val) actual_arg);
    bool is_true();
    bool equals(PTR(Val) other_val);
    std::string to_string();
};

#endif /* NumVal_hpp */
