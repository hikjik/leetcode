#pragma once

#include <vector>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static std::vector<long long> sumOfThree(long long num) {
    if (num % 3) {
      return {};
    }
    return {num / 3 - 1, num / 3, num / 3 + 1};
  }
};
