#pragma once

#include <algorithm>
#include <stack>

// Time: O(1)
// Space: O(N)

class MinStack {
public:
  void push(int val) {
    stack.push({val, stack.empty() ? val : std::min(getMin(), val)});
  }

  void pop() { stack.pop(); }

  int top() const { return stack.top().val; }

  int getMin() const { return stack.top().min; }

private:
  struct Item {
    int val;
    int min;
  };

  std::stack<Item> stack;
};
