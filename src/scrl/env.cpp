#include <vector>
#include "scrl/env.hpp"

namespace scrl {
  Env::Env(): parent(nullptr) {}
  
  Env::Env(const Env &parent): parent(&parent) {}

  optional<Val> Env::find(const Str &name) const {
    if (auto found = bindings.find(name); found != bindings.end()) { return found->second; }
    if (parent) { return parent->find(name); }
    return nullopt;
  }
  
  void Env::bind(const Str &name, const Val &val) { bindings.insert(make_pair(name, val)); }

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
