#include <map>

#include "scrl/forms/id.hpp"
#include "scrl/forms/lit.hpp"
#include "scrl/read.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  ReadE read_form(VM &vm, IStream &in, Pos &pos) {
    read_ws(vm, in, pos);
    
    Char c;
    if (!in.get(c)) { return ReadE(nullopt, nullopt); }
    
    if (isdigit(c)) {
      in.unget();
      return read_int(vm, in, pos);
    } else if (isgraph(c)) {
      in.unget();
      return read_id(vm, in, pos);
    }
      
    return ReadE(nullopt, Error(pos, c, '?'));
  }
  
  ReadE read_id(VM &vm, IStream &in, Pos &pos) {
    const Pos fpos(pos);
    SStream buf;
    Char c;
    
    while (in.get(c)) {
      if (c == ';' || c == '}' || !isgraph(c)) {
	in.unget();
	break;
      }

      buf << c;
      pos.column++;
    }

    if (!buf.tellp()) {
      return ReadE(nullopt, nullopt);
    }

    return ReadE(Form(IdForm(fpos, buf.str())), nullopt);
  }

  ReadE read_int_base(VM &vm, IStream &in, Pos &pos, int base) {
    const Pos fpos = pos;
    Int v(0);
      
    static const map<Char, int8_t> cs = {
      {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
      {'8', 8}, {'9', 9}, {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14},
      {'f', 15}
    };
    
    auto ci(cs.end());
    Char c;
    
    while (in.get(c)) {
      if ((ci = cs.find(c)) == cs.end()) { break; }
      auto cv(ci->second);

      if (cv >= base) { return ReadE(nullopt, Error(pos, "Invalid Int: ", c)); }
      v = v * base + cv;
      pos.column++;
    }
    
    if (!in.eof()) { in.unget();}
    return ReadE(Form(LitForm(fpos, Val(vm.abc_lib.int_type, v))), nullopt);
  }

  ReadE read_int(VM &vm, IStream &in, Pos &pos) {
    return read_int_base(vm, in, pos, 10);
  }
  
  ReadE read_str(VM &vm, IStream &in, Pos &pos) {
    const Pos fpos(pos);
    SStream buf;
    Char c;
    
    while (in.get(c)) {
      if (c == '"') { break; }
      buf << c;
      pos.column++;
    }

    if (!buf.tellp()) { return ReadE(nullopt, nullopt); }
    return ReadE(Form(LitForm(fpos, Val(vm.abc_lib.str_type, buf.str()))), nullopt);
  }

  ReadE read_ws(VM &vm, IStream &in, Pos &pos) {
    Char c = 0;
    
    while (in.get(c)) {
      if (!isspace(c)) {
	in.unget();
	break;
      }
	  
      switch (c) {
      case ' ':
      case '\t':
	pos.column++;
	break;
      case '\n':
	pos.line++;
	pos.column = 1;
	break;
      };
    }

    return ReadE(nullopt, nullopt);
  }
}
