#ifndef SCRL_TYPE_PRIM_HPP
#define SCRL_TYPE_PRIM_HPP

#include "scrl/type.hpp"
#include "scrl/types.hpp"

namespace scrl {
  struct Prim;
  
  struct PrimType: Type<Prim *> {
    PrimType(const Str &name);
    virtual void dump(const Val &v, OStream &out) const;
    virtual E emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos);
    virtual bool eq(const Val &v1, const Val &v2) const;
  };
}

#endif
