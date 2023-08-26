#ifndef SCRL_FORM_ID_HPP
#define SCRL_FORM_ID_HPP

#include "scrl/form.hpp"

namespace scrl {
  struct IdForm: Form {
    struct Imp: Form::Imp {
      Str name;
      
      Imp(const Pos &pos, const Str &name);    
      void dump(OStream& out) const override;
      E emit(VM &vm, Env &env, Forms &args) const override;
    };

    IdForm(const Pos &pos, const Str &name);
  };
}

#endif
