#include "scrl/form.hpp"

namespace scrl {
  void Form::dump(OStream& out) const { imp->dump(out); }

  optional<Error> Form::emit(VM &vm, Env &env, Forms &args) const { return imp->emit(vm, env, args); }

  const Pos &Form::pos() const { return imp->pos(); }

  OStream &operator<<(OStream &out, const Form &f) {
    f.dump(out);
    return out;
  }
}
