#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace dp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int rob(const std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }

    std::vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < std::ssize(nums); ++i) {
      dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp.back();
  }
};

} // namespace dp

namespace optimized {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int rob(const std::vector<int> &nums) {
    int a = 0, b = 0;
    for (auto num : nums) {
      std::swap(a, b);
      b = std::max(b + num, a);
    }
    return b;
  }
};

} // namespace optimized
