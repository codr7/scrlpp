#ifndef SCRL_VM_HPP
#define SCRL_VM_HPP

#include <deque>
#include <filesystem>
#include <map>
#include <optional>
#include <vector>

#include "scrl/error.hpp"
#include "scrl/libs/abc.hpp"
#include "scrl/op.hpp"
#include "scrl/ops/trace.hpp"
#include "scrl/stack.hpp"
#include "scrl/task.hpp"
#include "scrl/types.hpp"

namespace scrl {
  namespace fs = std::filesystem;

  const unsigned int VERSION = 1;

  struct VM {
    AbcLib abc_lib;
    
    bool trace = false;
    fs::path path;
    deque<Task> tasks;
    vector<Op> ops;
    
    VM();
    PC emit_pc() const;

    template <typename T, typename...Args>
    PC emit(Args &&...args);

    template <typename T, typename...Args>
    PC emit_no_trace(Args &&...args);
    
    Task &task();
  };

  template <typename T, typename...Args>
  PC VM::emit(Args &&...args) {
    if (trace) { emit_no_trace<TraceOp>(); }
    return emit_no_trace<T, Args...>(forward<Args>(args)...);
  }

  template <typename T, typename...Args>
  PC VM::emit_no_trace(Args &&...args) {
    const PC pc = ops.size();
    ops.push_back(make_op<T>(forward<Args>(args)...));
    return pc;
  }

  inline Task &VM::task() { return tasks.front(); }

  E eval(VM &vm, PC &pc);
  void repl(VM &vm);
}

#endif
