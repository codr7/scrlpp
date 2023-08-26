#ifndef SCRL_OP_STOP_HPP
#define SCRL_OP_STOP_HPP

#include "scrl/op.hpp"

namespace scrl {
  struct StopOp: Op {
    struct Imp: Op::Imp {
      Imp();
      virtual void dump(ostream& out) const;
    };

    StopOp();
  };
}

#endif
