#include <fstream>
#include <iostream>
#include <locale>

#include "alang/ops/trace.hpp"
#include "alang/vm.hpp"

namespace alang {
  PC VM::emit_pc() const { return ops.size(); }

  PC VM::emit_no_trace() {
    const PC pc = ops.size();
    ops.emplace_back(Stop());
    return pc;
  }

  PC VM::emit() {
    if (trace) { ops[emit_no_trace()] = Trace(); }
    return emit_no_trace();
  }

  PC emit(const Op &op) {
    const PC pc = emit();
    ops[pc] = op;
    return pc;
  }
}
