#ifndef SCRL_TYPE_INT_HPP
#define SCRL_TYPE_INT_HPP

#include "scrl/type.hpp"
#include "scrl/types.hpp"

namespace scrl {
  struct IntType: Type<Int>::Imp {
    IntType(const Str &name);
    virtual void dump(const Val &v, OStream &out) const override;
    virtual bool eq(const Val &v1, const Val &v2) const override;
    virtual bool is_true(const Val &v) const override;
  };
}

#endif
