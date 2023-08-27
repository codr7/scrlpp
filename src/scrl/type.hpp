#ifndef SCRL_TYPE_HPP
#define SCRL_TYPE_HPP

#include <any>
#include <optional>
#include <string>

#include "scrl/error.hpp"
#include "scrl/form.hpp"

namespace scrl {
  using namespace std;

  struct Env;
  struct Lib;
  struct Val;
  
  struct AType {
    struct Imp {
      Str name;
    
      Imp(const Str &name);
      virtual ~Imp();
      virtual void dump(const Val &v, OStream &out) const = 0;
      virtual E emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos) const;
      virtual bool eq(const Val &v1, const Val &v2) const = 0;
      virtual bool is_true(const Val &v) const;
    };

    shared_ptr<const Imp> imp;

    AType(shared_ptr<const Imp> imp = nullptr);    
    void dump(const Val &v, OStream &out) const;
    E emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos) const;
    bool eq(const Val &v1, const Val &v2) const;
    bool is_true(const Val &v) const;
    const Str &name() const;
  };
  
  inline void AType::dump(const Val &v, OStream &out) const { return imp->dump(v, out); }
  
  inline E AType::emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos) const {
    return imp->emit(v, vm, env, args, pos);
  }
  
  inline bool AType::eq(const Val &v1, const Val &v2) const { return imp->eq(v1, v2); }
  
  inline bool AType::is_true(const Val &v) const { return imp->is_true(v); }

  inline const Str &AType::name() const { return imp->name; }

  ostream &operator <<(ostream &out, AType &t);
  bool operator ==(const AType &t1, const AType &t2);

  template <typename T>
  struct Type: AType {
    struct Imp: AType::Imp {
      using Value = T;
      Imp(const Str &name);
    };
      
    Type(shared_ptr<const Imp> imp = nullptr);
  };

  template <typename T>
  Type<T>::Type(shared_ptr<const Imp> imp): AType(imp) {}

  template <typename T>
  Type<T>::Imp::Imp(const Str &name): AType::Imp(name) {}

  template <typename T, typename...Args>
  Type<typename T::Value> make_type(Args &&...args) {
    return Type<typename T::Value>(make_shared<T>(forward<Args>(args)...));
  }
}

#endif
