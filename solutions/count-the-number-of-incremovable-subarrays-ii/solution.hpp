#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static long long incremovableSubarrayCount(const std::vector<int> &nums) {
    const int n = nums.size();

    int r = n - 1;
    while (r && nums[r - 1] < nums[r]) {
      --r;
    }
    if (r == 0) {
      return n * (n + 1LL) / 2;
    }

    long long ans = n - r + 1;
    for (int l = 0; l < n; ++l) {
      if (l && nums[l - 1] >= nums[l]) {
        break;
      }
      while (r < n && nums[l] >= nums[r]) {
        ++r;
      }
      ans += n - r + 1;
    }
    return ans;
  }
};
