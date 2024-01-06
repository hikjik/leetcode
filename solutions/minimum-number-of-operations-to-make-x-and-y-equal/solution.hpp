#pragma once

#include <queue>
#include <unordered_set>

// Time: O(X)
// Space: O(X)

class Solution {
public:
  static int minimumOperationsToMakeEqual(int x, int y) {
    std::unordered_set<int> seen{x};
    std::queue<std::pair<int, int>> queue{{{x, 0}}};
    while (!queue.empty()) {
      const auto [u, ops] = queue.front();
      queue.pop();

      if (u == y) {
        return ops;
      }

      if (u % 11 == 0 && !seen.contains(u / 11)) {
        seen.insert(u / 11);
        queue.push({u / 11, ops + 1});
      }
      if (u % 5 == 0 && !seen.contains(u / 5)) {
        seen.insert(u / 5);
        queue.push({u / 5, ops + 1});
      }
      if (u && !seen.contains(u - 1)) {
        seen.insert(u - 1);
        queue.push({u - 1, ops + 1});
      }
      if (!seen.contains(u + 1)) {
        seen.insert(u + 1);
        queue.push({u + 1, ops + 1});
      }
    }

    throw;
  }
};
