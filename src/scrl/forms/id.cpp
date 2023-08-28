#include "scrl/forms/id.hpp"
#include "scrl/forms/lit.hpp"
#include "scrl/vm.hpp"

namespace scrl {  
  IdForm::IdForm(const Pos &pos, const Str &name): pos(pos), name(name) {}

  template <>
  void dump(const IdForm &f, OStream &out) { out << f.name; }
  
  template <>
  E emit(const IdForm &f, VM &vm, Env &env, deque<Form> &args) {
    auto found = env.find(f.name);
    if (found) { return found->emit(vm, env, args, f.pos); }
    return Error(f.pos, f.name, '?');
  }
}
