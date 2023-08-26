#include "scrl/ops/stop.hpp"
#include "scrl/read.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  void repl(VM &vm) {
    cout << "scrl v" << VERSION << endl << endl;
    SStream buf;
  
    for (;;) {
    NEXT:
      cout << "  ";
      cout.flush();
	
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
	    cout.flush();
	    break;
	  }

	  if (!f) { break; }
	  fs.push_back(*f);
	}

	while (!fs.empty()) {
	  if (auto e = pop_front(fs).emit(vm, vm.task().env, fs); e) {
	    cout << *e << endl;
	    cout.flush();
	    goto NEXT;
	  }
	}

	buf.str("");
	buf.clear();
	vm.emit<StopOp>();
	
	if (auto e = eval(vm, start_pc); e) {
	  cout << *e << endl;
	  cout.flush();
	  break;
	}

	cout << vm.task().stack << endl;
	cout.flush();
      } else {
	buf << line << endl;
      }
    }
  }
}
