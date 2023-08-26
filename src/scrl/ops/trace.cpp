#include "scrl/ops/trace.hpp"

namespace scrl {
  TraceOp::Imp::Imp(): Op::Imp(OpCode::Trace) {}
  
  void TraceOp::Imp::dump(ostream& out) const { out << "Trace"; }

  TraceOp::TraceOp(): Op(make_shared<const Imp>()) {}
}
