#ifndef SCRL_TYPE_HPP
#define SCRL_TYPE_HPP

#include <any>
#include <optional>
#include <string>

#include "scrl/error.hpp"
#include "scrl/form.hpp"

namespace scrl {
  using namespace std;

  struct Env;
  struct Lib;
  struct Val;
  
  struct AType {
    Str name;
    
    AType(const Str &name);
    virtual void dump(const Val &v, OStream &out) const = 0;
    virtual E emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos);
    virtual bool eq(const Val &v1, const Val &v2) const = 0;
    virtual bool is_true(const Val &v) const;
  };
  
  ostream &operator <<(ostream &out, AType &t);
  bool operator ==(AType &t1, AType &t2);

  template <typename T>
  struct Type: AType {
    Type(const Str &name);
  };

  template <typename T>
  Type<T>::Type(const Str &name): AType(name) {}
}

#endif
