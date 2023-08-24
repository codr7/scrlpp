#ifndef ALANG_TASK_HPP
#define ALANG_TASK_HPP

#include <iostream>

#include "alang/env.hpp"

namespace alang {
  struct Task {
    istream *stdin;
    ostream *stdout;

    Env env;
    Stack stack;

    Task();
    void push(Type &type, any &&data);
    Val pop();
  };

  inline Task::Task(): stdin(&cin), stdout(&cout) {}

  inline void Task::push(Type &type, any &&data) { stack.emplace_back(type, move(data)); }

  inline Val Task::pop() { return pop_back(stack); }
}

#endif
