#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minStartValue(const std::vector<int> &nums) {
    int ans = 1;
    for (int sum = 0; auto a : nums) {
      sum += a;
      ans = std::max(ans, 1 - sum);
    }
    return ans;
  }
};
