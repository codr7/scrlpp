#include "scrl/types/bool.hpp"
#include "scrl/val.hpp"

namespace scrl {
  BoolType::BoolType(const Str &name): Type<bool>(name) {}

  void BoolType::dump(const Val &v, OStream &out) const { out << (v.as<bool>() ? 'T' : 'F'); }
  
  bool BoolType::eq(const Val &v1, const Val &v2) const { return v1.as<bool>() == v2.as<bool>(); }
  
  bool BoolType::is_true(const Val &v) const { return v.as<bool>(); }
}
