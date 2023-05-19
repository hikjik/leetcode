#pragma once

#include <queue>

class RecentCounter {
  static const int kPastFrames = 3000;

public:
  int ping(int t) {
    while (!queue.empty() && queue.front() < t - kPastFrames) {
      queue.pop();
    }
    queue.push(t);
    return queue.size();
  }

private:
  std::queue<int> queue;
};
