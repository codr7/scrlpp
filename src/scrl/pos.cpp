#include "scrl/pos.hpp"

namespace scrl {
  const Pos Pos::INVALID;

  ostream &operator <<(ostream &out, Pos p) {
    out << p.source << '@' << p.line << ':' << p.column;
    return out;
  }
}
