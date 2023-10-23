#pragma once

#include <vector>

class Solution {
public:
  static int maxAscendingSum(const std::vector<int> &nums) {
    int ans = 0;
    for (int prev = 0, sum = 0; auto num : nums) {
      sum = prev >= num ? num : sum + num;
      prev = num;
      ans = std::max(ans, sum);
    }
    return ans;
  }
};
