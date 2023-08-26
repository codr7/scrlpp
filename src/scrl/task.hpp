#ifndef SCRL_TASK_HPP
#define SCRL_TASK_HPP

#include <iostream>

#include "scrl/env.hpp"

namespace scrl {
  struct Task {
    istream *stdin;
    ostream *stdout;

    Env env;
    Stack stack;

    Task();
    void push(const Val &val);
    Val pop();
  };

  inline Task::Task(): stdin(&cin), stdout(&cout) {}

  inline void Task::push(const Val &val) { stack.push_back(val); }

  inline Val Task::pop() { return pop_back(stack); }
}

#endif
