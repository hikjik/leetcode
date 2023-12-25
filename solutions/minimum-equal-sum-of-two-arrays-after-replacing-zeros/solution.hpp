#pragma once

#include <vector>

// Time: O(N+M)
// Space: O(1)

class Solution {
public:
  static long long minSum(const std::vector<int> &nums1,
                          const std::vector<int> &nums2) {
    long long sum1 = 0;
    int zeros1 = 0;
    for (auto num : nums1) {
      sum1 += num;
      zeros1 += !num;
    }

    long long sum2 = 0;
    int zeros2 = 0;
    for (auto num : nums2) {
      sum2 += num;
      zeros2 += !num;
    }

    if (!zeros1 && sum1 < zeros2 + sum2 || !zeros2 && sum2 < zeros1 + sum1) {
      return -1;
    }
    return std::max(zeros1 + sum1, zeros2 + sum2);
  }
};
