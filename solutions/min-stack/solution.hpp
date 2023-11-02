#pragma once

#include <algorithm>
#include <stack>

// Time:
// Space:

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    stack_.push(val);
    if (!min_stack_.empty()) {
      val = std::min(val, min_stack_.top());
    }
    min_stack_.push(val);
  }

  void pop() {
    stack_.pop();
    min_stack_.pop();
  }

  int top() { return stack_.top(); }

  int getMin() { return min_stack_.top(); }

private:
  std::stack<int> stack_;
  std::stack<int> min_stack_;
};
