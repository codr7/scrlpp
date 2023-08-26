#ifndef SCRL_LIB_HPP
#define SCRL_LIB_HPP

#include "scrl/env.hpp"

namespace scrl {
  struct Lib: Env {
    Lib();
    Lib(const Lib &parent);
  };
}

#endif 
