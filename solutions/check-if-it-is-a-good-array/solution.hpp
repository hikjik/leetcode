#pragma once

#include <numeric>
#include <vector>

// M = max(nums)
// Time: O(NlogM)
// Space: O(1)

class Solution {
public:
  static bool isGoodArray(const std::vector<int> &nums) {
    int gcd = nums[0];
    for (auto num : nums) {
      gcd = std::gcd(gcd, num);
    }
    return gcd == 1;
  }
};
