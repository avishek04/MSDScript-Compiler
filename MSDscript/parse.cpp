//
//  parse.cpp
//  Expression
//
//  Created by Avishek Choudhury on 2/21/23.
// 

#include "parse.hpp"
#include "AddExpr.hpp"
#include "MultExpr.hpp"
#include "EqExpr.hpp"
#include "IfExpr.hpp"
#include "BoolExpr.hpp"
#include "NumExpr.hpp"
#include "_letExpr.hpp"
#include "VariableExpr.hpp"
#include "FunExpr.hpp"
#include "CallExpr.hpp"
#include "Val.hpp"
#include <ctype.h>
#include <sstream>
#include <limits.h>

PTR(Expr) parse_str(std::string s) {
    std::stringstream ss;
    ss << s;
    return parse_expr(ss);
}

static void consume(std::istream& in, int expect) {
    int c = in.get();
    if (c != expect) {
        throw std::runtime_error("consume mismatch");
    }
}

void skip_whitespace(std::istream& in) {
    while (1) {
        int c = in.peek();
        if (!isspace(c))
            break;
        consume(in, c);
    }
}

PTR(Expr) parse_num(std::istream& in) {
    long n = 0;
    bool negative = false;
    
    if (in.peek() == '-') {
        negative = true;
        consume(in, '-');
    }
    
    while (1) {
        int c = in.peek();
        if (isdigit(c)) {
            consume(in, c);
            n = n*10 + (c - '0');
        }
        else
            break;
    }
    
    if (negative)
        n = -n;

    if (n > INT_MAX || n < INT_MIN) {
        throw std::runtime_error("Number overflow");
    }
    
    return NEW(NumExpr) (n);
}

PTR(Expr) parse_var(std::istream& in) {
    std::string var = "";
    
    while (1) {
        int c = in.peek();
        if (!isalpha(c)) {
            break;
        }
        var += c;
        consume(in, c);
    }
    return NEW(VariableExpr) (var);
}

std::string parse_keyword(std::istream& in) {
    int c = '_';
    std::string var = "_";
    consume(in, c);
    while (1) {
        c = in.peek();
        if (!isalpha(c)) {
            break;
        }
        var += c;
        consume(in, c);
    }
    // if (!isspace(c) && c != EOF && c != '(' && c != '\n' && c != ')') {
    //     throw std::runtime_error("Invalid input9");
    // }
    return var;
    // for (char c: keyword)
    // {
    //     if (in.peek() != c)
    //     {
    //         throw std::runtime_error("invalid input");
    //     }
    //     consume(in, c);
    // }
}

PTR(Expr) parse_true(std::istream& in) {
    skip_whitespace(in);
    return NEW(BoolExpr) (true);
}

PTR(Expr) parse_false(std::istream& in) {
    skip_whitespace(in);
    return NEW(BoolExpr) (false);
}

PTR(Expr) parse_if(std::istream& in) {
    PTR(Expr) condition;
    PTR(Expr) trueExp;
    PTR(Expr) falseExp;

    skip_whitespace(in);
    condition = parse_expr(in);

    skip_whitespace(in);
    int c = in.peek();
    std::string kw = "";
    if (c == '_') {
        kw = parse_keyword(in);
    }
    if (kw != "_then") {
        throw std::runtime_error("Invalid input8"); 
    }

    skip_whitespace(in);
    trueExp = parse_expr(in);

    skip_whitespace(in);
    c = in.peek();
    if (c == '_') {
        kw = parse_keyword(in);
    }
    if (kw != "_else") {
        throw std::runtime_error("Invalid input7"); 
    }

    skip_whitespace(in);
    falseExp = parse_expr(in);

    return NEW(IfExpr) (condition, trueExp, falseExp);
}

PTR(Expr) parse_let(std::istream& in) {
    std::string var = "";
    PTR(Expr) rhs;
    PTR(Expr) body;
    
    // parse_keyword(in, "_let");
    skip_whitespace(in);
    
    var = parse_var(in)->to_string();
    skip_whitespace(in);
    
    consume(in, '=');
    skip_whitespace(in);
    
    rhs = parse_expr(in);
    skip_whitespace(in);
    
    int c = in.peek();
    std::string kw = "";
    if (c == '_') {
        kw = parse_keyword(in);
    }
    if (kw != "_in") {
        throw std::runtime_error("Invalid input6");   
    }
    skip_whitespace(in);
    body = parse_expr(in);
    skip_whitespace(in);

    return NEW(_letExpr) (var, rhs, body);
}

PTR(Expr) parse_fun(std::istream& in) {
    std::string var = "";
    PTR(Expr) body;
    
    // parse_keyword(in, "_let");
    skip_whitespace(in);
    consume(in, '(');
    var = parse_var(in)->to_string();
    skip_whitespace(in);
    consume(in, ')');
    skip_whitespace(in);
    body = parse_expr(in);
    skip_whitespace(in);

    return NEW(FunExpr) (var, body);
}

PTR(Expr) parse_expr(std::istream& in) {
    PTR(Expr) rhs;
    PTR(Expr) e = parse_comparg(in);
    skip_whitespace(in);
    int c = in.peek();
    if (c == '=') {
        consume(in, '=');
        int c = in.peek();
        if (c == '=') {
            consume(in, '=');
            skip_whitespace(in);
            rhs = parse_expr(in);
            e = NEW(EqExpr) (e, rhs);
            skip_whitespace(in);
            // c = in.peek();
        }
        else {
            throw std::runtime_error("Invalid input5");
        }
    }
    
    // if (c == '=') {
    //     consume(in, '+');
    //     Expr* rhs = parse_comparg(in);
    //     e = new AddExpr(e, rhs);
    //     skip_whitespace(in);
    //     c = in.peek();
    // }
    skip_whitespace(in);
    // if (c != EOF && c != ')' && c != '_' && c != '\n') {
    //     throw std::runtime_error("Invalid input4");
    // }
    return e;
}

PTR(Expr) parse_comparg(std::istream& in) {
    PTR(Expr) e = parse_addend(in);
    skip_whitespace(in);
    int c = in.peek();
    
    if (c == '+') {
        consume(in, '+');
        PTR(Expr) rhs = parse_comparg(in);
        e = NEW(AddExpr) (e, rhs);
        skip_whitespace(in);
        // c = in.peek();
    }
    skip_whitespace(in);
    // if (c != EOF && c != ')' && c != '_' && c != '\n') {
    //     throw std::runtime_error("Invalid input3");
    // }
    return e;
}

PTR(Expr) parse_addend(std::istream& in) {
    PTR(Expr) e = parse_multicand(in);
    skip_whitespace(in);
    int c = in.peek();
    
    if (c == '*') {
        consume(in, '*');
        skip_whitespace(in);
        PTR(Expr) rhs = parse_addend(in);
        return NEW(MultExpr) (e, rhs);
    }
    else {
        return e;
    }
}

PTR(Expr) parse_multicand(std::istream& in) {
    PTR(Expr) expr = parse_inner(in);

    while (in.peek() == '(') {
        consume(in, '(');
        PTR(Expr) actual_arg = parse_expr(in);
        consume(in, ')');
        expr = NEW(CallExpr) (expr, actual_arg);
    }
    return expr;
}

PTR(Expr) parse_inner(std::istream& in) {
    skip_whitespace(in);
    int c = in.peek();
    
    if ((c == '-') || isdigit(c)) {
        return parse_num(in);
    }
    else if (c == '(') {
        consume(in, '(');
        PTR(Expr) e = parse_expr(in);
        skip_whitespace(in);
        c = in.peek();
        if (c != ')') {
            throw std::runtime_error("missing close parenthesis");
        }
        else {
            consume(in, ')');
        }
        return e;
    }
    else if (isalpha(c)){
        PTR(Expr) e = parse_var(in);
        skip_whitespace(in);
        return e;
    }
    else if (c == '_') {
        std::string kw = parse_keyword(in);
        if (kw == "_let") {
            return parse_let(in);
        }
        else if (kw == "_false") {
            return parse_false(in);
        }
        else if (kw == "_true") {
            return parse_true(in);
        }
        else if (kw == "_if") {
            return parse_if(in);
        }
        else if (kw == "_fun") {
            return parse_fun(in);
        }
        else {
            throw std::runtime_error("invalid input1");
        }
    }
    else {
        consume(in, c);
        throw std::runtime_error("invalid input2");
    }
}
