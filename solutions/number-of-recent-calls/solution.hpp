#pragma once

#include <queue>

/*
  933. Number of Recent Calls
  https://leetcode.com/problems/number-of-recent-calls/
  Difficulty: Easy
  Tags: Design, Queue, Data Stream
  Time:
  Space:
*/

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
