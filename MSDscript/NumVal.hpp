//
//  NumVal.hpp
//  
//
//  Created by Avishek Choudhury on 3/14/23.
//

#ifndef NumVal_hpp
#define NumVal_hpp

#include "Val.hpp"
#include "Expr.hpp"
#include "pointer.hpp"

class NumVal : public Val {
public:
    int rep;
    NumVal(long rep);
    PTR(Val) add_to(PTR(Val) other_val);
    PTR(Val) mult_with(PTR(Val) other_val);
    PTR(Val) call(PTR(Val) actual_arg);
    bool equals(PTR(Val) other_val);
    bool is_true();
    std::string to_string();
};

#endif /* NumVal_hpp */
