#ifndef ALANG_ERROR_HPP
#define ALANG_ERROR_HPP

#include <optional>
#include <string>

#include "alang/pos.hpp"
#include "alang/util.hpp"

namespace alang {
  using namespace std;
  
  struct Error {
    const Pos pos;
    const string message;

    template <typename...Args>
    Error(const Pos &pos, Args &&...args): pos(pos), message(format(forward<Args>(args)...)) {}
  };

  using E = optional<Error>;
  
  ostream &operator <<(ostream &out, const Error &e);
}

#endif
