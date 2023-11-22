#pragma once

#include <cmath>
#include <vector>

// Time: O(N^2)
// Space: O(1)

class Solution {
public:
  static int maximumStrongPairXor(const std::vector<int> &nums) {
    int ans = 0;
    for (auto a : nums) {
      for (auto b : nums) {
        if (std::abs(a - b) <= std::min(a, b)) {
          ans = std::max(ans, a ^ b);
        }
      }
    }
    return ans;
  }
};
