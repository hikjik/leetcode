#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countHillValley(std::vector<int> nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    int hills = 0, valleys = 0;
    for (int i = 1; i + 1 < std::ssize(nums); ++i) {
      if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
        ++hills;
      } else if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
        ++valleys;
      }
    }
    return hills + valleys;
  }
};
