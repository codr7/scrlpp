#include "alang/type.hpp"
#include "alang/val.hpp"

namespace alang {
  Val::Val(Type &type, any &&data): type(&type), data(move(data)) {}

  Val::Val(Type &type, const any &data): type(&type), data(data) {}

  E Val::emit(Env &env) const { return type->emit(*this, env); }

  ostream &operator <<(ostream &out, const Val &v) {
    v.type->dump(v, out);
    return out;
  }

  bool operator ==(const Val &v1, const Val &v2) {
    return v1.type == v2.type && v1.type->eq(v1, v2);
  }
}
