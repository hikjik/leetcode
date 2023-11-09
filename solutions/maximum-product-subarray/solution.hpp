#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxProduct(const std::vector<int> &nums) {
    int ans = nums[0];
    int max = 1, min = 1;
    for (auto num : nums) {
      if (num < 0) {
        std::swap(max, min);
      }
      max = std::max(num, num * max);
      min = std::min(num, num * min);
      ans = std::max(ans, max);
    }
    return ans;
  }
};
