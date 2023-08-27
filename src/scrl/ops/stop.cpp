#include "scrl/ops/stop.hpp"

namespace scrl {
  StopOp::StopOp(): Op::Imp(OpCode::Stop) {}
  
  void StopOp::dump(ostream& out) const { out << "Stop"; }
}
