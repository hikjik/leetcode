#pragma once

#include <queue>

/*
  225. Implement Stack using Queues
  https://leetcode.com/problems/implement-stack-using-queues/
  Difficulty: Easy
  Tags: Stack, Design, Queue
  Time:
  Space:
*/

class MyStack {
public:
  void push(int x) {
    queue_.push(x);
    for (int sz = queue_.size() - 1; sz; --sz) {
      queue_.push(pop());
    }
  }

  int pop() {
    const auto x = top();
    queue_.pop();
    return x;
  }

  int top() { return queue_.front(); }

  bool empty() { return queue_.empty(); }

private:
  std::queue<int> queue_;
};
