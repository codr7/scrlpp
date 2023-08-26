#ifndef SCRL_LIB_ABC_HPP
#define SCRL_LIB_ABC_HPP

#include "scrl/lib.hpp"
#include "scrl/types/int.hpp"
#include "scrl/types/str.hpp"

namespace scrl {
  struct AbcLib: Lib {
    IntType int_type;
    StrType str_type;
    AbcLib();
  };
}

#endif
