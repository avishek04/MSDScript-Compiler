#include "ExtendedEnv.hpp"

ExtendedEnv::ExtendedEnv(std::string name, PTR(Val) val, PTR(Env) rest) {
    this->name = name;
    this->val = val;
    this->rest = rest;
}

PTR(Val) ExtendedEnv::lookup(std::string find_name) {
    if (find_name == name) {
        return val;
    }
    else {
        return rest->lookup(find_name);
    }
}