#pragma once

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  static int minimumDifference(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < std::ssize(nums); ++i) {
      ans = std::min(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
  }
};
