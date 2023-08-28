#ifndef SCRL_FORM_ID_HPP
#define SCRL_FORM_ID_HPP

#include "scrl/form.hpp"

namespace scrl {
  struct IdForm {
    Pos pos;
    Str name;
    
    IdForm(const Pos &pos, const Str &name);    
  };

  template <>
  void dump(const IdForm &f, OStream& out);

  template <>
  E emit(const IdForm &f, VM &vm, Env &env, Forms &args);
}

#endif
