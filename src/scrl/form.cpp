#include "scrl/form.hpp"

namespace scrl {
  Form::Imp::Imp(Pos pos): pos(pos) {}
  Form::Imp::~Imp() {}

  Form::Form(shared_ptr<const Imp> imp): imp(imp) {}

  void Form::dump(OStream& out) const { imp->dump(out); }

  optional<Error> Form::emit(VM &vm, Env &env, Forms &args) const { return imp->emit(vm, env, args); }

  OStream &operator<<(OStream &out, const Form &f) {
    f.dump(out);
    return out;
  }
}
