#ifndef SCRL_STACK_HPP
#define SCRL_STACK_HPP

#include <vector>
#include "scrl/val.hpp"

namespace scrl {
  using Stack = vector<Val>;
  
  ostream &operator <<(ostream &out, const Stack &s);
}

#endif
