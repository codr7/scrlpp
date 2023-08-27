#include <iostream>

#include "scrl/forms/lit.hpp"
#include "scrl/ops/push.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  LitForm::LitForm(Pos pos, const Val &val): Form::Imp(pos), val(val) {}

  void LitForm::dump(OStream &out) const { val.dump(out); }
  
  E LitForm::emit(VM &vm, Env &env, Forms &args) const {
    vm.emit<PushOp>(val);
    return nullopt;
  }
}
