#include "alang/error.hpp"

namespace alang {
  ostream &operator <<(ostream &out, const Error &e) {
    out << e.pos << ' ' << e.message;
    return out;
  }
}
