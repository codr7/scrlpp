#include "scrl/ops/prim_call.hpp"
#include "scrl/ops/push.hpp"
#include "scrl/ops/stop.hpp"
#include "scrl/ops/trace.hpp"
#include "scrl/vm.hpp"

#define DISPATCH(next_pc)						\
  goto *dispatch[static_cast<int>((op = vm.ops[pc = vm.task().pc = (next_pc)]).code())] \

namespace scrl {
  E eval(VM &vm, PC &pc) {
    static const void* dispatch[] = {
      &&PRIM_CALL, &&PUSH, &&TRACE,
      &&STOP
    };
    
    Op op;
    DISPATCH(pc);
    
  PRIM_CALL: {
      auto &c(op.as<PrimCallOp>());
      pc++;
      c.target.call(vm, pc, c.pos);
      DISPATCH(pc);
    }

  PUSH: {
      vm.task().push(op.as<PushOp>().val);
      DISPATCH(pc+1);
    }
    
  TRACE: {
      cout << pc << ' ';
      vm.ops[pc+1].dump(cout);
      cout << endl;
      cout.flush();
      DISPATCH(pc+1);
    }
    
  STOP:
    return nullopt;
  }
}
