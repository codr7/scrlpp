#include "scrl/ops/trace.hpp"

namespace scrl {
  TraceOp::TraceOp(): Op::Imp(OpCode::Trace) {}
  
  void TraceOp::dump(ostream& out) const { out << "Trace"; }
}
