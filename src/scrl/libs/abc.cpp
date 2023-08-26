#include "scrl/libs/abc.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  AbcLib::AbcLib(VM &vm):
    Lib(vm),
    bool_type("Bool"),
    int_type("Int"),
    prim_type("Prim"),
    str_type("Str") {
    bind_prim("trace", 0, [](const Prim &prim, VM &vm, PC &pc, Pos pos) -> E {
      vm.trace = !vm.trace;
      vm.task().push(Val(vm.abc_lib.bool_type, vm.trace));
      return nullopt;
    });
  }
}
