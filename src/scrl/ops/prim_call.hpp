#ifndef SCRL_OP_PRIM_CALL_HPP
#define SCRL_OP_PRIM_CALL_HPP

#include "scrl/op.hpp"
#include "scrl/val.hpp"

namespace scrl {
  struct Prim;
  
  struct PrimCallOp: Op::Imp {
    Prim &target;
    Pos pos;
      
    PrimCallOp(Prim &target, Pos pos);
    virtual void dump(ostream& out) const;
  };
}

#endif
