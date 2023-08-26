#include "scrl/ops/prim_call.hpp"

namespace scrl {
  PrimCallOp::Imp::Imp(Prim &target, Pos pos): Op::Imp(OpCode::PrimCall), target(target), pos(pos) {}
  
  void PrimCallOp::Imp::dump(ostream& out) const { out << "PrimCall"; }

  PrimCallOp::PrimCallOp(Prim &target, Pos pos): Op(make_shared<const Imp>(target, pos)) {}
}
