#include "scrl/error.hpp"

namespace scrl {
  OStream &operator <<(OStream &out, const Error &e) {
    out << e.pos << ' ' << e.message;
    return out;
  }
}
