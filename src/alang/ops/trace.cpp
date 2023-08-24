#include "alang/ops/trace.hpp"

namespace alang {
  Trace::Imp::Imp(): Op::Imp(OpCode::Trace) {}
  
  void Trace::Imp::dump(ostream& out) const { out << "Trace"; }

  Trace::Trace(): Op(make_shared<const Imp>()) {}
}
