#include <deque>
#include <functional>
#include <iostream>

#include "scrl/vm.hpp"

using namespace std;

using Args = deque<string>;

static int repl_cmd(Args &args) {
  scrl::Pos pos("init", 1, 1);
  scrl::VM vm;

  if (auto e = vm.task().env.import(vm.abc_lib, {}, pos); e) {
    cout << *e << endl;
    return -1;
  }

  scrl::repl(vm);
  return 0;
}

using Cmd = function<int (Args &args)>;

int main(int argc, char *argv[]) {
  static const map<string, Cmd> cmds = {
    {"repl", repl_cmd}
  };
  
  optional<Cmd> cmd;
  int i = 1;
  
  if (argc > 1) {
    auto found = cmds.find(argv[1]);
    
    if (found != cmds.end()) {
      cmd = found->second;
      i++;
    }
  }

  if (!cmd) { cmd = repl_cmd; }

  Args args;
  for (; i < argc; i++) { args.push_back(argv[i]); }
  return (*cmd)(args);
}

