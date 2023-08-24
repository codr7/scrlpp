#include "alang/pos.hpp"

namespace alang {
  const Pos Pos::INVALID;

  ostream &operator <<(ostream &out, Pos p) {
    out << p.source << '@' << p.line << ':' << p.column;
    return out;
  }
}
