#ifndef SCRL_TYPE_STR_HPP
#define SCRL_TYPE_STR_HPP

#include "scrl/type.hpp"
#include "scrl/types.hpp"

namespace scrl {
  struct StrType: Type<Str> {
    StrType(const Str &name);
    virtual void dump(const Val &v, OStream &out) const;
    virtual bool eq(const Val &v1, const Val &v2) const;
    virtual bool is_true(const Val &v) const;
  };
}

#endif
