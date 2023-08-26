#include "scrl/vm.hpp"

namespace scrl {
  Lib::Lib(VM &vm): Env(vm) {}
  
  Lib::Lib(VM &vm, const Lib &parent): Env(vm, parent) {}
}
