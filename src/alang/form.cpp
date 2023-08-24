#include "alang/form.hpp"

namespace alang {
  Form::Imp::Imp(Pos pos): pos(pos) {}
  Form::Imp::~Imp() {}

  Form::Form(shared_ptr<const Imp> imp): imp(imp) {}

  void Form::dump(ostream& out) const { imp->dump(out); }

  optional<Error> Form::emit(Env &env) const { return imp->emit(env); }

  ostream &operator<<(ostream &out, Form val) {
    val.dump(out);
    return out;
  }
}
