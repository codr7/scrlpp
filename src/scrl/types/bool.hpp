#ifndef SCRL_TYPE_BOOL_HPP
#define SCRL_TYPE_BOOL_HPP

#include "scrl/type.hpp"
#include "scrl/types.hpp"

namespace scrl {
  struct BoolType: Type<bool> {
    BoolType(const Str &name);
    virtual void dump(const Val &v, OStream &out) const;
    virtual bool eq(const Val &v1, const Val &v2) const;
    virtual bool is_true(const Val &v) const;
  };
}

#endif
