#ifndef SCRL_ENV_HPP
#define SCRL_ENV_HPP

#include <map>

#include "scrl/prim.hpp"
#include "scrl/val.hpp"

namespace scrl {
  struct Env {
    VM &vm;
    const Env *parent;
    map<Str, Val> bindings;

    Env(VM &vm);
    Env(VM &vm, const Env &parent);
    void bind(const Str &name, const Val &val);
    Prim &bind_prim(const Str &name, int nargs, Prim::Body body);
    optional<Val> find(const Str &name) const;    
    E import(const Env &source, initializer_list<Str> names, const Pos &pos);
  };

  inline Env::Env(VM &vm): vm(vm), parent(nullptr) {}
  
  inline Env::Env(VM &vm, const Env &parent): vm(vm), parent(&parent) {}
}

#endif
