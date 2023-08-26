#include "scrl/ops/push.hpp"
#include "scrl/ops/stop.hpp"
#include "scrl/ops/trace.hpp"
#include "scrl/vm.hpp"

#define DISPATCH(next_pc)						\
  goto *dispatch[static_cast<int>((op = vm.ops[pc = (next_pc)]).code())] \

namespace scrl {
  E eval(VM &vm, PC &pc) {
    static const void* dispatch[] = {
      &&PUSH, &&TRACE,
      &&STOP
    };
    
    Op op;
    DISPATCH(pc);
    
  PUSH: {
      vm.task().push(op.as<PushOp>().val);
      DISPATCH(pc+1);
    }
    
  TRACE: {
      vm.ops[pc+1].dump(cout);
      DISPATCH(pc+1);
    }
    
  STOP:
    return nullopt;
  }
}
