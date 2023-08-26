#ifndef SCRL_READ_HPP
#define SCRL_READ_HPP

#include <functional>
#include <optional>

#include "scrl/form.hpp"
#include "scrl/error.hpp"
#include "scrl/types.hpp"

namespace scrl {
  using namespace std;

  using ReadE = pair<optional<Form>, E>;

  struct VM;

  ReadE read_form(VM &vm, IStream &in, Pos &pos);
  ReadE read_id(VM &vm, IStream &in, Pos &pos);
  ReadE read_int_base(VM &vm, IStream &in, Pos &pos, int base);
  ReadE read_int(VM &vm, IStream &in, Pos &pos);
  ReadE read_str(VM &vm, IStream &in, Pos &pos);
  ReadE read_ws(VM &vm, IStream &in, Pos &pos);
}

#endif
