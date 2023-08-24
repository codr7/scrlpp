#ifndef ALANG_STACK_HPP
#define ALANG_STACK_HPP

#include <vector>
#include "alang/val.hpp"

namespace alang {
  using Stack = vector<Val>;
  
  ostream &operator <<(ostream &out, const Stack &s);
}

#endif
