#pragma once

#include <vector>

class Solution {
public:
  static int minimizeArrayValue(const std::vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = 1e9;
    while (l < r) {
      const auto m = l + (r - l) / 2;
      long long sum = 0;
      for (int i = n - 1; i > 0; --i) {
        sum = std::max(0LL, sum + nums[i] - m);
      }
      nums[0] + sum > m ? l = m + 1 : r = m;
    }
    return l;
  }
};
