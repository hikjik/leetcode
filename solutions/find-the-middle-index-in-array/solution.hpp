#pragma once

#include <numeric>
#include <vector>

class Solution {
public:
  static int findMiddleIndex(const std::vector<int> &nums) {
    auto left = 0, right = std::accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < std::ssize(nums); ++i) {
      right -= nums[i];
      if (left == right) {
        return i;
      }
      left += nums[i];
    }
    return -1;
  }
};
