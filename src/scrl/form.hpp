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
    struct AImp {      
      virtual ~AImp() = default;
      virtual void dump(OStream& out) const = 0;
      virtual E emit(VM &vm, Env &env, Forms &args) const = 0;
      virtual const Pos &pos() const = 0;
    };

    template <typename T>
    struct Imp: AImp {
      T data;
      Imp(T data);
      void dump(OStream& out) const override;
      E emit(VM &vm, Env &env, Forms &args) const override;
      const Pos &pos() const override;
    };

    shared_ptr<const AImp> imp;

    template <typename T>
    Form(T imp);
    
    void dump(OStream& out) const;
    E emit(VM &vm, Env &env, Forms &args) const;
    const Pos &pos() const;

    template <typename T, typename...Args>
    const T &as() const { return *static_cast<const T *>(imp.get()); }
  };

  template <typename T>
  Form::Form(T imp): imp(make_shared<Imp<T>>(move(imp))) {}
  
  template <typename T>
  Form::Imp<T>::Imp(T data): data(move(data)) {}

  template <typename T>
  void dump(const T &, OStream&);
    
  template <typename T>
  void Form::Imp<T>::dump(OStream& out) const { scrl::dump(data, out); }
  
  template <typename T>
  E emit(const T &, VM &, Env &, Forms &);

  template <typename T>
  E Form::Imp<T>::emit(VM &vm, Env &env, Forms &args) const { return scrl::emit(data, vm, env, args); }

  template <typename T>
  const Pos &Form::Imp<T>::pos() const { return data.pos; }

  OStream &operator<<(OStream &out, const Form &f);
}

#endif
