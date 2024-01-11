#pragma once

#include <functional>
#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N2^N)
// Space: O(2^N)

namespace memo {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static bool canPartitionKSubsets(std::vector<int> nums, int k) {
    const auto sum = std::reduce(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
      return false;
    }

    const auto target = sum / k;
    std::ranges::sort(nums, std::greater{});

    std::vector<int> memo(1 << nums.size(), -1);

    std::function<bool(int, int, int, int)> backtrack = [&](int i, int mask,
                                                            int sum, int cnt) {
      if (sum == target) {
        return memo[mask] = backtrack(0, mask, 0, cnt + 1);
      }
      if (cnt == k - 1) {
        return 1;
      }
      if (sum > target) {
        return 0;
      }
      if (memo[mask] != -1) {
        return memo[mask];
      }

      for (int j = i; j < std::ssize(nums); ++j) {
        if (mask & 1 << j) {
          continue;
        }
        if (backtrack(j + 1, mask | 1 << j, sum + nums[j], cnt)) {
          return memo[mask] = 1;
        }
      }
      return memo[mask] = 0;
    };

    return backtrack(0, 0, 0, 0);
  }
};

} // namespace memo

namespace dp {

// Time: O(N2^N)
// Space: O(2^N)
class Solution {
public:
  static bool canPartitionKSubsets(const std::vector<int> &nums, int k) {
    const int n = nums.size();
    const auto sum = std::reduce(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
      return false;
    }
    const auto target = sum / k;

    std::vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int mask = 0; mask < std::ssize(dp); ++mask) {
      if (dp[mask] == -1) {
        continue;
      }
      for (int i = 0; i < n; ++i) {
        if (!(mask & 1 << i) && nums[i] + dp[mask] <= target) {
          dp[mask | 1 << i] = (nums[i] + dp[mask]) % target;
        }
      }
    }
    return !dp.back();
  }
};

} // namespace dp
