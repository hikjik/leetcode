#pragma once

#include <deque>

// S = 1000
// Time: O(QS)
// Space: O(S)

class HitCounter {
public:
  // O(1)
  void hit(int timestamp) { deque.push_back(timestamp); }

  // O(S)
  int getHits(int timestamp) {
    while (!deque.empty() && timestamp - deque.front() >= 300) {
      deque.pop_front();
    }
    return deque.size();
  }

private:
  std::deque<int> deque;
};
