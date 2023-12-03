#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> findPeaks(const std::vector<int> &nums) {
    std::vector<int> ans;
    for (int i = 1; i < std::ssize(nums) - 1; ++i) {
      if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
