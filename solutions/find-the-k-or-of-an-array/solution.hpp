#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int findKOr(const std::vector<int> &nums, int k) {
    int ans = 0;
    for (int i = 0; i < 31; ++i) {
      if (k <= std::ranges::count_if(nums, [=](int a) { return a & 1 << i; })) {
        ans |= 1 << i;
      }
    }
    return ans;
  }
};
