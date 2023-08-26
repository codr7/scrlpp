#include "scrl/prim.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  Prim::Prim(const Str &name, int nargs, Body body): name(name), nargs(nargs), body(body) {}

  E Prim::call(VM &vm, PC &pc, Pos pos) const { return body(*this, vm, pc, pos); }

  ostream &operator <<(ostream &out, const Prim &p) {
    out << "Prim(" << p.name << ')';
    return out;
  }
}
