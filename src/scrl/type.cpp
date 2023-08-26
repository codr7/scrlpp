#include "scrl/ops/push.hpp"
#include "scrl/type.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  AbstractType::AbstractType(const Str &name): name(name) {}

  E AbstractType::emit(const Val &v, VM &vm, Env &env, Forms &args) {
    vm.emit(PushOp(v));
    return nullopt;
  }

  bool AbstractType::is_true(const Val &v) const { return true; }

  ostream &operator <<(ostream &out, AbstractType &t) {
      out << t.name;
      return out;
  }

  bool operator ==(const AbstractType &t1, const AbstractType &t2) {
    return &t1 == &t2;
  }
}
