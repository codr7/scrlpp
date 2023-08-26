#include "scrl/stack.hpp"

namespace scrl {
  ostream &operator <<(ostream &out, const Stack &s) {
    out << '[';
    int i = 0;
    
    for (const Val &v: s) {
      if (i++) { out << ' '; }
      out << v;
    }

    out << ']';
    return out;
  }
}
