#ifndef SCRL_POS_HPP
#define SCRL_POS_HPP

#include <string>
#include <ostream>

namespace scrl {
  using namespace std;

  struct Pos {
    static const Pos INVALID;
    
    Pos(const string &source = "*invalid*", int line = -1, int column = -1):
      source(source), line(line), column(column) {}
    
    string source;
    int line, column;
  };

  ostream &operator <<(ostream &out, Pos p);
}

#endif
