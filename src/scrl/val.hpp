#ifndef SCRL_VAL_HPP
#define SCRL_VAL_HPP

#include <any>
#include <optional>

#include "scrl/error.hpp"
#include "scrl/type.hpp"

namespace scrl {
  using namespace std;

  struct Env;
  struct VM;
  
  struct Val {
    AbstractType *type;
    any data;

    template <typename T>
    Val(Type<T> &type, T &&data);

    template <typename T>
    Val(Type<T> &type, const T &data);
    
    void dump(ostream &out) const;
    E emit(VM &vm, Env &env, Forms &args) const;
    
    template <typename T>
    T as() const;

    operator bool() const { return type->is_true(*this); }
  };

  template <typename T>
  Val::Val(Type<T> &type, T &&data): type(&type), data(move(data)) {}

  template <typename T>
  Val::Val(Type<T> &type, const T &data): type(&type), data(data) {}
  
  template <typename T>
  T Val::as() const { return any_cast<T>(data); }

  ostream &operator <<(ostream &out, const Val &v);
  bool operator ==(const Val &v1, const Val &v2);
}

#endif
