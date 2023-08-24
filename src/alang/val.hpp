#ifndef ALANG_VAL_HPP
#define ALANG_VAL_HPP

#include <any>
#include <optional>

#include "alang/error.hpp"
#include "alang/type.hpp"

namespace alang {
  using namespace std;

  struct Env;
  struct Type;
  struct VM;
  
  struct Val {
    Type *type;
    any data;

    Val(Type &type, any &&data);
    Val(Type &type, const any &data);
    E emit(Env &env) const;
      
    template <typename T>
    T as() const { return any_cast<T>(data); }

    operator bool() const { return type->is_true(*this); }
  };

  ostream &operator <<(ostream &out, const Val &v);
  bool operator ==(const Val &v1, const Val &v2);
}

#endif
