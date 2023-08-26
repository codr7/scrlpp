#include <iostream>

#include "scrl/forms/lit.hpp"

namespace scrl {
  LitForm::LitForm(Pos pos, const Val &val): Form(make_shared<const Imp>(pos, val)) {}

  LitForm::Imp::Imp(Pos pos, const Val &val): Form::Imp(pos), val(val) {}

  void LitForm::Imp::dump(OStream &out) const { val.dump(out); }
  
  E LitForm::Imp::emit(VM &vm, Env &env, Forms &args) const { return val.emit(vm, env, args); }
}
