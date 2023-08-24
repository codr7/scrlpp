#ifndef ALANG_FORM_HPP
#define ALANG_FORM_HPP

#include <memory>
#include <string>
#include <optional>
#include <ostream>

#include "alang/error.hpp"
#include "alang/pos.hpp"

namespace alang {
  using namespace std;

  struct Env;
  
  struct Form {
    struct Imp {      
      Pos pos;

      Imp(Pos pos);
      virtual ~Imp();
      virtual void dump(ostream& out) const = 0;
      virtual E emit(Env &env) const = 0;
    };

    shared_ptr<const Imp> imp;
    
    Form(shared_ptr<const Imp> imp = nullptr);
    void dump(ostream& out) const;
    E emit(Env &env) const;

    template <typename T>
    const typename T::Imp &as() const { return *static_cast<const typename T::Imp *>(imp.get()); }
  };

  ostream &operator<<(ostream &out, Form val);
}

#endif
