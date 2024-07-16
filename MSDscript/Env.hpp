//
//  Expr.hpp
//  
//
//  Created by Avishek Choudhury on 1/24/23.
//

/**
* \file Expr.hpp
* \brief Expr class
**
Holds the signature for all the methods of the Expr class
*/
#ifndef Env_hpp
#define Env_hpp

#include "catch.h"
#include <stdio.h>
#include <sstream>
#include "pointer.hpp"
#include "Val.hpp"

class Val;

CLASS(Env) {
public:
    virtual PTR(Val) lookup(std::string find_name) = 0;
};

#endif /* Env_hpp */
