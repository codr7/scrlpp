#include <vector>
#include "scrl/env.hpp"
#include "scrl/vm.hpp"

namespace scrl {
  void Env::bind(const Str &name, const Val &val) {
    bindings.insert(make_pair(name, val));
  }

  void Env::bind_prim(Prim &p) {
    bind(p.name, Val(vm.abc_lib.prim_type, p));
  }

  optional<Val> Env::find(const Str &name) const {
    if (auto found = bindings.find(name); found != bindings.end()) { return found->second; }
    if (parent) { return parent->find(name); }
    return nullopt;
  }
  
  E Env::import(const Env &source, initializer_list<Str> names, const Pos &pos) {
    vector<Str> ns(names);

    if (ns.empty()) {
      bindings.insert(source.bindings.begin(), source.bindings.end());
    } else {
      for (const Str &n: ns) {
	auto v = source.find(n);
	if (!v) { return Error(pos, n, '?'); }
	bindings.insert(make_pair(n, *v));
      }
    }

    return nullopt;
  }
}
