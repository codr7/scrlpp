#include "scrl/forms/id.hpp"
#include "scrl/forms/lit.hpp"
#include "scrl/vm.hpp"

namespace scrl {  
  IdForm::Imp::Imp(const Pos &pos, const Str &name): Form::Imp(pos), name(name) {}

  void IdForm::Imp::dump(OStream &out) const { out << name; }
  
  E IdForm::Imp::emit(VM &vm, Env &env, deque<Form> &args) const {
    auto found = env.find(name);
    if (found) { return found->emit(vm, env, args, pos); }
    return Error(pos, name, '?');
  }

  IdForm::IdForm(const Pos &pos, const Str &name): Form(make_shared<const Imp>(pos, move(name))) {}
}
