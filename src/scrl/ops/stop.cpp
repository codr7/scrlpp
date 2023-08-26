#include "scrl/ops/stop.hpp"

namespace scrl {
  StopOp::Imp::Imp(): Op::Imp(OpCode::Stop) {}
  
  void StopOp::Imp::dump(ostream& out) const { out << "Stop"; }

  StopOp::StopOp(): Op(make_shared<const Imp>()) {}
}
