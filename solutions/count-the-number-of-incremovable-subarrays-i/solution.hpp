#pragma once

#include <ranges>
#include <vector>

// Time: O(N^3)
// Space: O(N)

class Solution {
public:
  static int incremovableSubarrayCount(const std::vector<int> &nums) {
    const int n = nums.size();
    int ans = 0;
    for (int l = 1; l <= n; ++l) {
      for (int i = 0; i + l <= n; ++i) {
        auto copy = nums;
        copy.erase(copy.begin() + i, copy.begin() + i + l);
        ans += std::ranges::is_sorted(copy, std::less_equal{});
      }
    }
    return ans;
  }
};
