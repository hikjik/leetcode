#pragma once

#include <numeric>
#include <vector>

// M = max(nums)
// Time: O(N^2logM)
// Space: O(1)

class Solution {
public:
  static int minOperations(const std::vector<int> &nums) {
    const int n = nums.size();
    const auto ones = std::ranges::count(nums, 1);
    if (ones) {
      return n - ones;
    }

    int ops = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int gcd = nums[i];
      for (int j = i + 1; j < n; ++j) {
        gcd = std::gcd(gcd, nums[j]);
        if (gcd == 1) {
          ops = std::min(ops, j - i);
          break;
        }
      }
    }
    return ops == INT_MAX ? -1 : ops + n - 1;
  }
};
