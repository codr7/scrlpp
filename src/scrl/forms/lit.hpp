#ifndef SCRL_FORMS_LIT_HPP
#define SCRL_FORMS_LIT_HPP

#include "scrl/form.hpp"
#include "scrl/val.hpp"

namespace scrl {  
  struct LitForm {
    Pos pos;
    Val val;
    
    LitForm(Pos pos, const Val &val);    
  };

  template <>
  void dump(const LitForm &f, OStream& out);

  template <>
  E emit(const LitForm &f, VM &vm, Env &env, Forms &args);
}

#endif
