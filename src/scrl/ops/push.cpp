#include "scrl/ops/push.hpp"

namespace scrl {
  PushOp::PushOp(const Val &val): Op::Imp(OpCode::Push), val(val) {}
  
  void PushOp::dump(ostream& out) const { out << "Push"; }
}
