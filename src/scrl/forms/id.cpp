#include "scrl/forms/id.hpp"
#include "scrl/forms/lit.hpp"
#include "scrl/vm.hpp"

namespace scrl {  
  IdForm::IdForm(const Pos &pos, const Str &name): Imp(pos), name(name) {}

  void IdForm::dump(OStream &out) const { out << name; }
  
  E IdForm::emit(VM &vm, Env &env, deque<Form> &args) const {
    auto found = env.find(name);
    if (found) { return found->emit(vm, env, args, pos); }
    return Error(pos, name, '?');
  }
}
