#ifndef SCRL_FORMS_LIT_HPP
#define SCRL_FORMS_LIT_HPP

#include "scrl/form.hpp"
#include "scrl/val.hpp"

namespace scrl {  
  struct LitForm: Form::Imp {
    Val val;
    
    LitForm(Pos pos, const Val &val);    
    void dump(OStream& out) const override;
    E emit(VM &vm, Env &env, Forms &args) const override;
  };
}

#endif
