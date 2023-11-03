#pragma once

#include <algorithm>
#include <limits>
#include <vector>

// Time: O(N)
// Space: O(1)
// Notes: [Kadane's algorithm](https://w.wiki/62dv)

namespace dp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int maxSubArray(const std::vector<int> &nums) {
    std::vector<int> dp(nums);
    for (int i = 1; i < std::ssize(dp); ++i) {
      dp[i] = std::max(dp[i], dp[i] + dp[i - 1]);
    }
    return std::ranges::max(dp);
  }
};

} // namespace dp

namespace kadane {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int maxSubArray(const std::vector<int> &nums) {
    auto max = std::numeric_limits<int>::min();
    for (int sum = 0; auto num : nums) {
      sum = std::max(sum + num, num);
      max = std::max(max, sum);
    }
    return max;
  }
};

} // namespace kadane
