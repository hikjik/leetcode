#pragma once

#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<int> numberGame(std::vector<int> nums) {
    std::ranges::sort(nums);
    for (int i = 0; i < std::ssize(nums); i += 2) {
      std::swap(nums[i], nums[i + 1]);
    }
    return nums;
  }
};
