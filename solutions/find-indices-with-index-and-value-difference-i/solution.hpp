#pragma once

#include <cmath>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> findIndices(const std::vector<int> &nums,
                                      int indexDifference,
                                      int valueDifference) {
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + indexDifference; j < n; ++j) {
        if (std::abs(nums[i] - nums[j]) >= valueDifference) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};
