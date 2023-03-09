#pragma once

#include <vector>

class Solution {
public:
  static int numSubarrayProductLessThanK(const std::vector<int> &nums, int k) {
    int prod = 1;
    int cnt = 0;
    for (size_t i = 0, j = 0; j < nums.size(); ++j) {
      prod *= nums[j];
      while (i <= j && k <= prod) {
        prod /= nums[i++];
      }
      cnt += j - i + 1;
    }
    return cnt;
  }
};
