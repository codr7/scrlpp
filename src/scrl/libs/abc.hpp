#ifndef SCRL_LIB_ABC_HPP
#define SCRL_LIB_ABC_HPP

#include "scrl/lib.hpp"
#include "scrl/types/bool.hpp"
#include "scrl/types/int.hpp"
#include "scrl/types/prim.hpp"
#include "scrl/types/str.hpp"

namespace scrl {
  struct AbcLib: Lib {
    Type<bool> bool_type;
    Type<Int> int_type;
    Type<Prim &> prim_type;
    Type<Str> str_type;

    Prim trace_prim;
    AbcLib(VM &vm);
  };
}

#endif
