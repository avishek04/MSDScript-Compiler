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
#ifndef Expr_hpp
#define Expr_hpp

#include <stdio.h>
#include <sstream>
#include "pointer.hpp"
#include "Val.hpp"
#include "Env.hpp"

//CLASS(Val);
class Val;

CLASS(Expr) {
public:
    typedef enum {
      prec_none,      // = 0
      prec_let,       // = 1
      prec_add,       // = 2
      prec_mult,      // = 3
    } precedence_t;
    
    virtual ~Expr() { }
    virtual bool equals(PTR(Expr) e) = 0;
    virtual PTR(Val) interp(PTR(Env)) = 0;
    virtual void print(std::ostream& ot) = 0;
    std::string to_string()
    {
        std::stringstream st("");
        this->print(st);
        return st.str();
    }
    std::string to_prettyString()
    {
        std::stringstream st("");
        this->pretty_print(st);
        return st.str();
    }
    void pretty_print(std::ostream& ot) {
        int otPos = ot.tellp();
        this -> pretty_print_at(prec_none, ot, otPos);
    }
    virtual void pretty_print_at(precedence_t precedence, std::ostream& ot, int otPos, bool braces = false) = 0;
};

#endif /* Expr_hpp */
