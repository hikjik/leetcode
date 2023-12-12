#pragma once

#include <climits>
#include <numeric>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int minimumSum(const std::vector<int> &nums) {
    const int n = nums.size();
    const auto min = [](int a, int b) { return std::min(a, b); };

    std::vector<int> prefixMin(n), suffixMin(n);
    std::partial_sum(nums.cbegin(), nums.cend(), prefixMin.begin(), min);
    std::partial_sum(nums.crbegin(), nums.crend(), suffixMin.rbegin(), min);

    int ans = INT_MAX;
    for (int i = 1; i < n - 1; ++i) {
      if (prefixMin[i - 1] < nums[i] && nums[i] > suffixMin[i + 1]) {
        ans = std::min(ans, prefixMin[i - 1] + nums[i] + suffixMin[i + 1]);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
