#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int nthUglyNumber(int n) {
    std::vector<int> nums{1};
    nums.reserve(n);

    size_t i2 = 0, i3 = 0, i5 = 0;

    while (--n) {
      const auto num = std::min({nums[i2] * 2, nums[i3] * 3, nums[i5] * 5});
      nums.push_back(num);

      i2 += nums[i2] * 2 == num;
      i3 += nums[i3] * 3 == num;
      i5 += nums[i5] * 5 == num;
    }

    return nums.back();
  }
};
