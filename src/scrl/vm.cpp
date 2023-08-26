#include <fstream>
#include <iostream>
#include <locale>

#include "scrl/ops/trace.hpp"
#include "scrl/ops/stop.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  VM::VM(): abc_lib(*this) { tasks.emplace_back(*this); }

  PC VM::emit_pc() const { return ops.size(); }
}
