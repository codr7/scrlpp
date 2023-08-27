#ifndef SCRL_OP_PUSH_HPP
#define SCRL_OP_PUSH_HPP

#include "scrl/op.hpp"
#include "scrl/val.hpp"

namespace scrl {
  struct PushOp: Op::Imp {
    Val val;
      
    PushOp(const Val &val);
    virtual void dump(ostream& out) const;
  };
}

#endif
