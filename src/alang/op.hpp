#ifndef ALANG_OP_HPP
#define ALANG_OP_HPP

#include <memory>

#include "alang/form.hpp"
#include "alang/pos.hpp"

namespace alang {
  enum class OpCode {Push, Stop, Trace};
  
  struct Op {
    struct Imp {
      OpCode code;
      optional<Form> form;

      Imp(OpCode code, const optional<Form> form = nullopt);
      virtual ~Imp();
      virtual void dump(ostream& out) const = 0;
    };

    shared_ptr<const Imp> imp;
    
    Op(shared_ptr<const Imp> imp = nullptr);
    void dump(ostream& out) const;

    template <typename T>
    const typename T::Imp &as() const { return *static_cast<const typename T::Imp *>(imp.get()); }
  };

  ostream &operator<<(ostream &out, Op val);
}

#endif
