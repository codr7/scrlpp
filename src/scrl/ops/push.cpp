#include "scrl/ops/push.hpp"

namespace scrl {
  PushOp::Imp::Imp(const Val &val): Op::Imp(OpCode::Push), val(val) {}
  
  void PushOp::Imp::dump(ostream& out) const { out << "Push"; }

  PushOp::PushOp(const Val &val): Op(make_shared<const Imp>(val)) {}
}
