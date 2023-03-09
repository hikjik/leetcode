#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int> addToArrayForm(const std::vector<int> &nums, int k) {
    std::vector<int> sum;

    for (int i = nums.size() - 1; i >= 0 || k; --i) {
      const auto num = k + (i >= 0 ? nums[i] : 0);
      sum.push_back(num % 10);
      k = num / 10;
    }

    std::reverse(sum.begin(), sum.end());
    return sum;
  }
};
