#pragma once

#include <queue>

// Time: O(N^2)
// Space: O(N)

namespace two_queue {

class MyStack {
public:
  // O(N)
  void push(int x) {
    queue2.push(x);
    while (!empty()) {
      queue2.push(pop());
    }
    std::swap(queue1, queue2);
  }

  // O(1)
  int pop() {
    const auto x = top();
    queue1.pop();
    return x;
  }

  // O(1)
  int top() const { return queue1.front(); }

  // O(1)
  bool empty() const { return queue1.empty(); }

private:
  std::queue<int> queue1, queue2;
};

} // namespace two_queue

namespace one_queue {

class MyStack {
public:
  // O(N)
  void push(int x) {
    queue.push(x);
    for (int sz = queue.size() - 1; sz; --sz) {
      queue.push(pop());
    }
  }

  // O(1)
  int pop() {
    const auto x = top();
    queue.pop();
    return x;
  }

  // O(1)
  int top() const { return queue.front(); }

  // O(1)
  bool empty() const { return queue.empty(); }

private:
  std::queue<int> queue;
};

} // namespace one_queue
