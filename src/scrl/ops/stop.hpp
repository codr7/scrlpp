#ifndef SCRL_OP_STOP_HPP
#define SCRL_OP_STOP_HPP

#include "scrl/op.hpp"

namespace scrl {
  struct StopOp: Op::Imp {
    StopOp();
    virtual void dump(ostream& out) const;
  };
}

#endif
