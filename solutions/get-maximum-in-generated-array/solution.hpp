#pragma once

class Solution {
public:
  static int getMaximumGenerated(int n) {
    std::vector<int> nums{0, 1};
    for (int i = 2; i <= n; ++i) {
      if (i & 1) {
        nums.push_back(nums[i / 2] + nums[i / 2 + 1]);
      } else {
        nums.push_back(nums[i / 2]);
      }
    }
    return *std::max_element(nums.begin(), nums.begin() + n + 1);
  }
};
