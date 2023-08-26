#ifndef SCRL_ENV_HPP
#define SCRL_ENV_HPP

#include <map>

#include "scrl/val.hpp"

namespace scrl {
  struct Env {
    const Env *parent;
    map<Str, Val> bindings;

    Env();
    Env(const Env &parent);
    optional<Val> find(const Str &name) const;
    void bind(const Str &name, const Val &val);
    E import(const Env &source, initializer_list<Str> names, const Pos &pos);
  };
}

#endif
