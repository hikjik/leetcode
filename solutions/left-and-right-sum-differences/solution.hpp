#pragma once

#include <cmath>
#include <numeric>
#include <vector>

// Time:  O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> leftRightDifference(const std::vector<int> &nums) {
    auto left = 0, right = std::reduce(nums.begin(), nums.end(), 0);
    std::vector<int> ans;
    for (auto num : nums) {
      right -= num;
      ans.push_back(std::abs(right - left));
      left += num;
    }
    return ans;
  }
};
