#include "scrl/types/int.hpp"
#include "scrl/val.hpp"

namespace scrl {
  IntType::IntType(const Str &name): Type<Int>(name) {}

  void IntType::dump(const Val &v, OStream &out) const { out << v.as<Int>(); }
  
  bool IntType::eq(const Val &v1, const Val &v2) const { return v1.as<Int>() == v2.as<Int>(); }
  
  bool IntType::is_true(const Val &v) const { return v.as<Int>(); }
}
