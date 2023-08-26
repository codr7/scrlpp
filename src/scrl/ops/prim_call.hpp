#ifndef SCRL_OP_PRIM_CALL_HPP
#define SCRL_OP_PRIM_CALL_HPP

#include "scrl/op.hpp"
#include "scrl/val.hpp"

namespace scrl {
  struct Prim;
  
  struct PrimCallOp: Op {
    struct Imp: Op::Imp {
      Prim &target;
      Pos pos;
      
      Imp(Prim &target, Pos pos);
      virtual void dump(ostream& out) const;
    };

    PrimCallOp(Prim &target, Pos pos);
  };
}

#endif
