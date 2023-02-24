#pragma once

#include <stack>

class MyQueue {
public:
  MyQueue() {}

  void push(int x) { to_push.push(x); }

  int pop() {
    auto x = peek();
    to_pop.pop();
    return x;
  }

  int peek() {
    if (to_pop.empty()) {
      move();
    }
    return to_pop.top();
  }

  bool empty() { return to_pop.empty() && to_push.empty(); }

private:
  void move() {
    while (!to_push.empty()) {
      to_pop.push(to_push.top());
      to_push.pop();
    }
  }

  std::stack<int> to_push;
  std::stack<int> to_pop;
};
