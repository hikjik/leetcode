#pragma once

#include <queue>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int leastInterval(const std::vector<char> &tasks, int n) {
    std::vector<int> counter(26, 0);
    for (auto c : tasks) {
      counter[c - 'A']++;
    }

    std::priority_queue<int> queue;
    for (auto a : counter) {
      if (a) {
        queue.push(a);
      }
    }

    int intervals = 0;
    while (!queue.empty()) {
      std::vector<int> waiting;

      for (int i = 0; i <= n && !queue.empty(); ++i) {
        waiting.push_back(queue.top() - 1);
        queue.pop();
      }

      for (auto a : waiting) {
        if (a) {
          queue.push(a);
        }
      }

      intervals += queue.empty() ? waiting.size() : n + 1;
    }
    return intervals;
  }
};
