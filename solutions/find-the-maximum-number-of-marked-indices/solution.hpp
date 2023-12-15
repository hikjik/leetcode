#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static int maxNumOfMarkedIndices(std::vector<int> nums) {
    std::ranges::sort(nums);

    int ans = 0;
    const int n = nums.size();
    for (int j = n - 1, i = n / 2 - 1; i >= 0; --i) {
      if (2 * nums[i] <= nums[j]) {
        ans += 2;
        --j;
      }
    }
    return ans;
  }
};
