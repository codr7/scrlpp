#include "scrl/libs/abc.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  AbcLib::AbcLib(VM &vm):
    Lib(vm),
    bool_type(make_type<BoolType>("Bool")),
    int_type(make_type<IntType>("Int")),
    prim_type(make_type<PrimType>("Prim")),
    str_type(make_type<StrType>("Str")),

    trace_prim("trace", 0, [](const Prim &prim, VM &vm, PC &pc, Pos pos) -> E {
      vm.trace = !vm.trace;
      vm.task().push(Val(vm.abc_lib.bool_type, vm.trace));
      return nullopt;
    }) {
    bind("T", Val(bool_type, true));
    bind("F", Val(bool_type, false));

    bind_prim(trace_prim);
  }
}
