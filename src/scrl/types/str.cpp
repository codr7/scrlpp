#include "scrl/types/str.hpp"
#include "scrl/val.hpp"

namespace scrl {
  StrType::StrType(const Str &name): Type<Str>(name) {}

  void StrType::dump(const Val &v, OStream &out) const { out << v.as<Str>(); }
  
  bool StrType::eq(const Val &v1, const Val &v2) const { return v1.as<Str>() == v2.as<Str>(); }
  
  bool StrType::is_true(const Val &v) const { return v.as<Str>().length(); }
}
