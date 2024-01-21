#pragma once

#include <climits>
#include <utility>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minimumCost(const std::vector<int> &nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 1; i < std::ssize(nums); ++i) {
      if (nums[i] < min1) {
        min2 = std::exchange(min1, nums[i]);
      } else if (nums[i] < min2) {
        min2 = nums[i];
      }
    }
    return nums[0] + min1 + min2;
  }
};
