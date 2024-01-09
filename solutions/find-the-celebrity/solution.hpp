#pragma once

#include <functional>

// Time: O(N)
// Space: O(1)

std::function<bool(int, int)> knows;

class Solution {
public:
  static int findCelebrity(int n) {
    int candidate = 0;
    for (int i = 1; i < n; ++i) {
      if (!knows(i, candidate)) {
        candidate = i;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i != candidate) {
        if (knows(candidate, i) || !knows(i, candidate)) {
          return -1;
        }
      }
    }
    return candidate;
  }
};
