#ifndef SCRL_PRIM_HPP
#define SCRL_PRIM_HPP

#include <functional>

#include "scrl/error.hpp"

namespace scrl {
  struct VM;

  struct Prim {
    using Body = function<E (const Prim &prim, VM &vm, PC &pc, Pos pos)>;
    
    Prim(const Str &name, int nargs, Body body);
    E call(VM &vm, PC &pc, Pos pos) const;
    
    Str name;
    int nargs;
    Body body;
  };

  ostream &operator <<(ostream &out, const Prim &p);
}

#endif
