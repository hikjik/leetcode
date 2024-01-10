#pragma once

#include <functional>
#include <vector>

// Time: O(M^2)
// Space: O(M)

namespace memo {

// Time: O(M^2)
// Space: O(M^2)
class Solution {
public:
  static int maximumScore(const std::vector<int> &nums,
                          const std::vector<int> &multipliers) {
    const int n = nums.size(), m = multipliers.size();
    std::vector memo(m, std::vector<int>(m, -1));

    std::function<int(int, int)> maxScore = [&](int op, int left) -> int {
      if (op == m) {
        return 0;
      }
      if (memo[op][left] != -1) {
        return memo[op][left];
      }
      memo[op][left] = std::max(
          nums[left] * multipliers[op] + maxScore(op + 1, left + 1),
          nums[n - (op - left) - 1] * multipliers[op] + maxScore(op + 1, left));
      return memo[op][left];
    };

    return maxScore(0, 0);
  }
};

} // namespace memo

namespace dp {

// Time: O(M^2)
// Space: O(M^2)
class Solution {
public:
  static int maximumScore(const std::vector<int> &nums,
                          const std::vector<int> &multipliers) {
    const int n = nums.size(), m = multipliers.size();
    std::vector dp(m + 1, std::vector<int>(m + 1));
    for (int op = m - 1; op >= 0; --op) {
      for (int left = 0; left <= op; ++left) {
        dp[op][left] = std::max(
            nums[left] * multipliers[op] + dp[op + 1][left + 1],
            nums[n - (op - left) - 1] * multipliers[op] + dp[op + 1][left]);
      }
    }
    return dp[0][0];
  }
};

} // namespace dp

namespace opt {

// Time: O(M^2)
// Space: O(M)
class Solution {
public:
  static int maximumScore(const std::vector<int> &nums,
                          const std::vector<int> &multipliers) {
    const int n = nums.size(), m = multipliers.size();
    std::vector<int> dp(m + 1);
    for (int op = m - 1; op >= 0; --op) {
      for (int left = 0; left <= op; ++left) {
        dp[left] =
            std::max(nums[left] * multipliers[op] + dp[left + 1],
                     nums[n - (op - left) - 1] * multipliers[op] + dp[left]);
      }
    }
    return dp[0];
  }
};

} // namespace opt
