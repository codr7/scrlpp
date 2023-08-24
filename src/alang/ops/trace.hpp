#ifndef ALANG_OP_TRACE_HPP
#define ALANG_OP_TRACE_HPP

#include "alang/op.hpp"

namespace alang {
  struct Trace: Op {
    struct Imp: Op::Imp {
      Imp();
      virtual void dump(ostream& out) const;
    };

    Trace();
  };
}

#endif
