#pragma once

#include <cmath>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> findDuplicates(std::vector<int> nums) {
    std::vector<int> ans;
    for (auto a : nums) {
      const auto index = std::abs(a) - 1;
      if (nums[index] < 0) {
        ans.push_back(index + 1);
      }
      nums[index] = -nums[index];
    }
    return ans;
  }
};
