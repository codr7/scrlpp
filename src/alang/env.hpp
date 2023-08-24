#ifndef ALANG_ENV_HPP
#define ALANG_ENV_HPP

#include <map>

#include "alang/val.hpp"

namespace alang {
  struct Env {
    map<string, Val> bindings;
        
    optional<Val> find(const string &name) const;
    void bind(const string &name, Type &type, any &&data);
    void bind(const string &name, Type &type, const any &data);
    E import(const Env &source, initializer_list<string> names, const Pos &pos);
  };
}

#endif
