#include "alang/type.hpp"
#include "alang/vm.hpp"

namespace alang {
  Type::Type(Lib &lib, const string &name): lib(lib), name(name) {}

  ostream &operator <<(ostream &out, Type &t) {
      out << t.name;
      return out;
  }

  bool operator ==(const Type &t1, const Type &t2) {
    return &t1 == &t2;
  }
}
