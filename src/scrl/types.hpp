#ifndef SCRL_TYPES_HPP
#define SCRL_TYPES_HPP

#include <cstdint>
#include <string>
#include <sstream>

namespace scrl {
  using namespace std;
  using Int = int64_t;
  using PC = uint64_t;
  using Char = char;
  using IStream = basic_istream<Char>;
  using OStream = basic_ostream<Char>;
  using Str = basic_string<Char>;
  using SStream = basic_stringstream<Char>;
}

#endif
