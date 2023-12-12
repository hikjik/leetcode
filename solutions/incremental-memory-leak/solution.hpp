#pragma once

#include <vector>

// Time: O(sqrt(M))
// Space: O(1)

class Solution {
public:
  static std::vector<int> memLeak(int memory1, int memory2) {
    int i = 1;
    while (std::max(memory1, memory2) >= i) {
      memory1 >= memory2 ? memory1 -= i : memory2 -= i;
      ++i;
    }
    return {i, memory1, memory2};
  }
};
