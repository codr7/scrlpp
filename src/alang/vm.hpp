#ifndef ALANG_VM_HPP
#define ALANG_VM_HPP

#include <filesystem>
#include <map>
#include <optional>
#include <vector>

#include "alang/error.hpp"
#include "alang/op.hpp"
#include "alang/stack.hpp"
#include "alang/task.hpp"
#include "alang/types.hpp"

namespace alang {
  namespace fs = std::filesystem;

  const unsigned int VERSION = 1;

  struct VM {
    bool trace = false;
    fs::path path;
    Task main, *task;
    vector<Op> ops;
    
    VM();
    PC emit_pc() const;
    PC emit_no_trace();
    PC emit();
    PC emit(const Op &op);
  };

  VM::VM(): task(&main) {}

  E eval(VM &vm, PC &pc);
  void repl(VM &vm);
}

#endif
