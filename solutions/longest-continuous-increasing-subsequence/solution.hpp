#pragma once

#include <vector>

class Solution {
public:
  static int findLengthOfLCIS(const std::vector<int> &nums) {
    int ans = 1;
    for (int i = 1, l = 1; i <= std::ssize(nums); ++i, ++l) {
      if (i == std::ssize(nums) || nums[i] <= nums[i - 1]) {
        ans = std::max(ans, l);
        l = 0;
      }
    }
    return ans;
  }
};
