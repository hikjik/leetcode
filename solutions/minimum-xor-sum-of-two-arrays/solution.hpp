#pragma once

#include <bit>
#include <climits>
#include <vector>

// Time: O(N2^N)
// Space: O(N2^N)

namespace memo {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int minimumXORSum(const std::vector<int> &nums1,
                           const std::vector<int> &nums2) {
    const int n = nums1.size(), m = 1 << n;
    std::vector<int> memo(m, INT_MAX);
    return minimumXORSum(m - 1, nums1, nums2, &memo);
  }

  static int minimumXORSum(unsigned mask, const std::vector<int> &nums1,
                           const std::vector<int> &nums2,
                           std::vector<int> *memo) {
    if (mask == 0) {
      return 0;
    }
    auto &ans = (*memo)[mask];
    if (ans == INT_MAX) {
      const int n = nums1.size();
      const int i = std::popcount(mask) - 1;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          ans = std::min(
              ans, (nums1[i] ^ nums2[j]) +
                       minimumXORSum(mask ^ (1 << j), nums1, nums2, memo));
        }
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static int minimumXORSum(const std::vector<int> &nums1,
                           const std::vector<int> &nums2) {
    const int n = nums1.size();
    std::vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;

    for (unsigned mask = 0; mask < dp.size(); ++mask) {
      const auto i = std::popcount(mask);
      for (int j = 0; j < n; ++j) {
        if (!(mask & (1 << j))) {
          dp[mask | (1 << j)] =
              std::min(dp[mask | (1 << j)], (nums1[i] ^ nums2[j]) + dp[mask]);
        }
      }
    }
    return dp.back();
  }
};

} // namespace dp
