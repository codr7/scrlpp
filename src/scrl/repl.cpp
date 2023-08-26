#include "scrl/ops/stop.hpp"
#include "scrl/read.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  void repl(VM &vm) {
    SStream buf;
  
    for (;;) {
    NEXT:
      cout << "  ";
     
      Str line;
      if (!getline(cin, line)) { break; }
       
      if (line.empty()) {
	Pos pos("repl", 1, 1);
	PC start_pc = vm.emit_pc();
	Forms fs;
	
	for (;;) {
	  auto [f, e] = read_form(vm, buf, pos);

	  if (e) {
	    cout << *e << endl;
	    break;
	  }

	  if (!f) { break; }
	  fs.push_back(*f);
	}

	while (!fs.empty()) {
	  if (auto e = pop_front(fs).emit(vm, vm.task().env, fs); e) {
	    cout << *e << endl;
	    goto NEXT;
	  }
	}

	buf.str("");
	buf.clear();
	vm.emit(StopOp());
	
	if (auto e = eval(vm, start_pc); e) {
	  cout << *e << endl;
	  break;
	}

	cout << vm.task().stack << endl;
      } else {
	buf << line << endl;
      }
    }
  }
}
