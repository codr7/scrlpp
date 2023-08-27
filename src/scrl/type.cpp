#include "scrl/ops/push.hpp"
#include "scrl/type.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  AType::AType(const Str &name): name(name) {}

  E AType::emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos) {
    vm.emit<PushOp>(v);
    return nullopt;
  }

  bool AType::is_true(const Val &v) const { return true; }

  ostream &operator <<(ostream &out, AType &t) {
      out << t.name;
      return out;
  }

  bool operator ==(const AType &t1, const AType &t2) {
    return &t1 == &t2;
  }
}
