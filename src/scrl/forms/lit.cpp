#include <iostream>

#include "scrl/forms/lit.hpp"
#include "scrl/ops/push.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  LitForm::LitForm(Pos pos, const Val &val): pos(pos), val(val) {}

  template <>
  void dump(const LitForm &f, OStream &out) { f.val.dump(out); }
  
  template <>
  E emit(const LitForm &f, VM &vm, Env &env, Forms &args) {
    vm.emit<PushOp>(f.val);
    return nullopt;
  }
}
