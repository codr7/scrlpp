#ifndef SCRL_OP_HPP
#define SCRL_OP_HPP

#include <memory>

#include "scrl/form.hpp"
#include "scrl/pos.hpp"

namespace scrl {
  enum class OpCode {
    PrimCall, Push, Trace,
    Stop
  };
  
  struct Op {
    struct Imp {
      OpCode code;

      Imp(OpCode code);
      virtual ~Imp();
      virtual void dump(ostream& out) const = 0;
    };

    shared_ptr<const Imp> imp;
    
    Op(shared_ptr<const Imp> imp = nullptr);
    OpCode code() const;
    void dump(ostream& out) const;

    template <typename T>
    const typename T::Imp &as() const { return *static_cast<const typename T::Imp *>(imp.get()); }
  };

  inline OpCode Op::code() const { return imp->code; }
  
  ostream &operator<<(ostream &out, Op val);
}

#endif
