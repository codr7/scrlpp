#include <fstream>
#include <iostream>
#include <locale>

#include "scrl/ops/trace.hpp"
#include "scrl/ops/stop.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  VM::VM() { tasks.emplace_back(); }

  PC VM::emit_pc() const { return ops.size(); }

  PC VM::emit_no_trace(const Op &op) {
    const PC pc = ops.size();
    ops.push_back(op);
    return pc;
  }

  PC VM::emit(const Op &op) {
    if (trace) { emit_no_trace(TraceOp()); }
    return emit_no_trace(op);
  }
}
