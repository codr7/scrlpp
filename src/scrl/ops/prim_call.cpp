#include "scrl/ops/prim_call.hpp"

namespace scrl {
  PrimCallOp::PrimCallOp(Prim &target, Pos pos): Op::Imp(OpCode::PrimCall), target(target), pos(pos) {}
  
  void PrimCallOp::dump(ostream& out) const { out << "PrimCall"; }
}
