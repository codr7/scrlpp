#include "scrl/op.hpp"

namespace scrl {
  Op::Imp::Imp(OpCode code): code(code) {}

  Op::Op(shared_ptr<const Imp> imp): imp(imp) {}

  void Op::dump(ostream& out) const { imp->dump(out); }

  ostream &operator<<(ostream &out, Op val) {
    val.dump(out);
    return out;
  }
}
