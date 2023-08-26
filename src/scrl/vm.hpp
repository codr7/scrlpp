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
    PC emit_no_trace(const Op &op);
    PC emit(const Op &op);
    Task &task();
  };

  inline Task &VM::task() { return tasks.front(); }

  E eval(VM &vm, PC &pc);
  void repl(VM &vm);
}

#endif
