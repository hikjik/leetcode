#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> leftRightDifference(const std::vector<int> &nums) {
    size_t n = nums.size();

    std::vector<int> left(n, 0);
    for (size_t i = 1; i < n; ++i) {
      left[i] = left[i - 1] + nums[i - 1];
    }

    std::vector<int> rights(n, 0);
    for (int i = n - 1; i > 0; --i) {
      rights[i - 1] = rights[i] + nums[i];
    }

    std::vector<int> diff(n, 0);
    for (size_t i = 0; i < n; ++i) {
      diff[i] = abs(rights[i] - left[i]);
    }
    return diff;
  }
};
