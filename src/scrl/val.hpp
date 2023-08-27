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
    AType type;
    any data;

    template <typename T>
    Val(const Type<T> &type, T &&data);

    template <typename T>
    Val(const Type<T> &type, const T &data);

    template <typename T>
    T &as();

    template <typename T>
    const T &as() const;

    void dump(ostream &out) const;
    E emit(VM &vm, Env &env, Forms &args, Pos pos) const;
    
    operator bool() const;
  };

  template <typename T>
  Val::Val(const Type<T> &type, T &&data): type(type), data(move(data)) {}

  template <typename T>
  Val::Val(const Type<T> &type, const T &data): type(type), data(data) {}
  
  template <typename T>
  T &Val::as() { return any_cast<T &>(data); }

  template <typename T>
  const T &Val::as() const { return any_cast<const T &>(data); }

  inline Val::operator bool() const { return type.is_true(*this); }

  ostream &operator <<(ostream &out, const Val &v);
  bool operator ==(const Val &v1, const Val &v2);
}

#endif
