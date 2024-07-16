//
//  parse.hpp
//  Expression
//
//  Created by Avishek Choudhury on 2/21/23.
//

#pragma once

#ifndef parse_hpp
#define parse_hpp

#include <iostream>
#include <string>
#include "Expr.hpp"
#include "pointer.hpp"

PTR(Expr) parse_str(std::string s);
static void consume(std::istream& in, int expect);
void skip_whitespace(std::istream& in);
PTR(Expr) parse_num(std::istream& in);
PTR(Expr) parse_var(std::istream& in);
std::string parse_keyword(std::istream& in);
PTR(Expr) parse_true(std::istream& in);
PTR(Expr) parse_false(std::istream& in);
PTR(Expr) parse_if(std::istream& in);
PTR(Expr) parse_let(std::istream& in);
PTR(Expr) parse_expr(std::istream& in);
PTR(Expr) parse_comparg(std::istream& in);
PTR(Expr) parse_addend(std::istream& in);
PTR(Expr) parse_multicand(std::istream& in);
PTR(Expr) parse_inner(std::istream& in);

#endif /* parse_hpp */
