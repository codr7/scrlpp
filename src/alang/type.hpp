#ifndef ALANG_TYPE_HPP
#define ALANG_TYPE_HPP

#include <any>
#include <optional>
#include <string>

#include "alang/error.hpp"

namespace alang {
  using namespace std;

  struct Env;
  struct Lib;
  struct Val;
  
  struct Type {
    Lib &lib;
    string name;
    
    Type(Lib &lib, const string &name);
    virtual bool is_true(const Val &v) const = 0;
    virtual void dump(const Val &v, ostream &out) const = 0;
    virtual E emit(const Val &v, Env &env) = 0;
    virtual bool eq(const Val &v1, const Val &v2) const = 0;
  };

  ostream &operator <<(ostream &out, Type &t);
  bool operator ==(Type &t1, Type &t2);
}

#endif
