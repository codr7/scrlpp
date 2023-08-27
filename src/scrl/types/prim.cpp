#include "scrl/ops/prim_call.hpp"
#include "scrl/prim.hpp"
#include "scrl/types/prim.hpp"
#include "scrl/val.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  PrimType::PrimType(const Str &name): Type<Prim *>::Imp(name) {}

  void PrimType::dump(const Val &v, OStream &out) const { out << *v.as<Prim *>(); }

  E PrimType::emit(const Val &v, VM &vm, Env &env, Forms &args, Pos pos) const {
    vm.emit<PrimCallOp>(*v.as<Prim *>(), pos);
    return nullopt;
  }

  bool PrimType::eq(const Val &v1, const Val &v2) const { return v1.as<Prim *>() == v2.as<Prim *>(); }
}
