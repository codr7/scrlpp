#include "scrl/type.hpp"
#include "scrl/val.hpp"

namespace scrl {
  void Val::dump(ostream &out) const { type->dump(*this, out); }

  E Val::emit(VM &vm, Env &env, Forms &args, Pos pos) const { return type->emit(*this, vm, env, args, pos); }

  ostream &operator <<(ostream &out, const Val &v) {
    v.type->dump(v, out);
    return out;
  }

  bool operator ==(const Val &v1, const Val &v2) {
    return v1.type == v2.type && v1.type->eq(v1, v2);
  }
}
