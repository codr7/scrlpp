#ifndef SCRL_OP_TRACE_HPP
#define SCRL_OP_TRACE_HPP

#include "scrl/op.hpp"

namespace scrl {
  struct TraceOp: Op::Imp {
    TraceOp();
    virtual void dump(ostream& out) const;
  };
}

#endif
