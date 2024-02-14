#pragma once

#include <vector>

// Time: O(NM)
// Space: O(N)

class Solution {
public:
  static int countMatchingSubarrays(const std::vector<int> &nums,
                                    const std::vector<int> &pattern) {
    const int n = nums.size() - 1, m = pattern.size();
    std::vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
      vals[i] = (nums[i + 1] > nums[i]) - (nums[i + 1] < nums[i]);
    }

    int ans = 0;
    for (int i = 0; i + m <= n; ++i) {
      ans += std::equal(pattern.begin(), pattern.end(), vals.begin() + i);
    }
    return ans;
  }
};
