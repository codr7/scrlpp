#include "scrl/vm.hpp"

namespace scrl {
  Lib::Lib(): Env() {}
  
  Lib::Lib(const Lib &parent): Env(parent) {}
}
