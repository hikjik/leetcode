#pragma once

#include <queue>

// Time: O(Q)
// Space: O(size)

class MovingAverage {
public:
  // O(1)
  MovingAverage(int size) : size(size) {}

  // O(1)
  double next(int val) {
    sum += val;
    queue.push(val);
    if (std::ssize(queue) > size) {
      sum -= queue.front();
      queue.pop();
    }
    return sum / queue.size();
  }

private:
  std::queue<int> queue;
  int size;
  double sum = 0.0;
};
