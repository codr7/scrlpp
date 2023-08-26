#ifndef SCRL_OP_TRACE_HPP
#define SCRL_OP_TRACE_HPP

#include "scrl/op.hpp"

namespace scrl {
  struct TraceOp: Op {
    struct Imp: Op::Imp {
      Imp();
      virtual void dump(ostream& out) const;
    };

    TraceOp();
  };
}

#endif
