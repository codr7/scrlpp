#include "alang/vm.hpp"

namespace alang {
  void repl(VM &vm) {
    stringstream buf;
  
    for (;;) {
    NEXT:
      cout << "  ";
     
      string line;
      if (!getline(cin, line)) { break; }
       
      if (line.empty()) {
	Pos pos("repl", 1, 1);
	PC start_pc = vm.emit_pc();

	for (;;) {
	  auto [f, e] = read_form(vm, buf, pos);

	  if (e) {
	    cout << *e << endl;
	    break;
	  }

	  if (!f) { break; }
	  
	  if (e = f->emit(vm.task->env); e) {
	    cout << *e << endl;
	    goto NEXT;
	  }
	}

	buf.str("");
	buf.clear();
	vm.emit();
	
	if (auto e = eval(vm, start_pc); e) {
	  cout << *e << endl;
	  break;
	}

	cout << vm.task->stack << endl;
      } else {
	buf << line << endl;
      }
    }
  }
}
