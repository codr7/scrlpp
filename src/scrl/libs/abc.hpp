#ifndef SCRL_LIB_ABC_HPP
#define SCRL_LIB_ABC_HPP

#include "scrl/lib.hpp"
#include "scrl/types/bool.hpp"
#include "scrl/types/int.hpp"
#include "scrl/types/prim.hpp"
#include "scrl/types/str.hpp"

namespace scrl {
  struct AbcLib: Lib {
    BoolType bool_type;
    IntType int_type;
    PrimType prim_type;
    StrType str_type;

    AbcLib(VM &vm);
  };
}

#endif
