#include <fstream>
#include <iostream>
#include <locale>

#include "scrl/ops/trace.hpp"
#include "scrl/ops/stop.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  VM::VM() { tasks.emplace_back(); }

  PC VM::emit_pc() const { return ops.size(); }
}
