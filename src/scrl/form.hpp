#ifndef SCRL_FORM_HPP
#define SCRL_FORM_HPP

#include <deque>
#include <memory>
#include <string>
#include <optional>
#include <ostream>

#include "scrl/error.hpp"
#include "scrl/pos.hpp"
#include "scrl/types.hpp"

namespace scrl {
  using namespace std;

  struct Form;
  using Forms = deque<Form>;

  struct Env;
  struct VM;
  
  struct Form {
    struct Imp {      
      Pos pos;

      Imp(Pos pos);
      virtual ~Imp();
      virtual void dump(OStream& out) const = 0;
      virtual E emit(VM &vm, Env &env, Forms &args) const = 0;
    };

    shared_ptr<const Imp> imp;
    
    Form(shared_ptr<const Imp> imp = nullptr);
    void dump(OStream& out) const;
    E emit(VM &vm, Env &env, Forms &args) const;

    template <typename T>
    const typename T::Imp &as() const { return *static_cast<const typename T::Imp *>(imp.get()); }
  };

  OStream &operator<<(OStream &out, const Form &f);
}

#endif
