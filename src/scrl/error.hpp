#ifndef SCRL_ERROR_HPP
#define SCRL_ERROR_HPP

#include <optional>
#include <string>

#include "scrl/pos.hpp"
#include "scrl/util.hpp"

namespace scrl {
  using namespace std;
  
  struct Error {
    Pos pos;
    Str message;

    template <typename...Args>
    Error(const Pos &pos, Args &&...args): pos(pos), message(format(forward<Args>(args)...)) {}
  };

  using E = optional<Error>;
  
  OStream &operator <<(OStream &out, const Error &e);
}

#endif
