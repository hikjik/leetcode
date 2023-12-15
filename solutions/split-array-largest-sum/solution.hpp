#pragma once

#include <climits>
#include <numeric>
#include <ranges>
#include <vector>

// N = nums.size(), M = sum(nums)
// Time: O(NlogM)
// Space: O(1)

namespace binary_search {

// Time: O(NlogM)
// Space: O(1)
class Solution {
public:
  static int splitArray(const std::vector<int> &nums, int k) {
    auto left = std::ranges::max(nums);
    auto right = std::accumulate(nums.begin(), nums.end(), 0) + 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;

      int cnt = 1;
      for (int sum = 0; auto num : nums) {
        if (sum + num > middle) {
          ++cnt;
          sum = 0;
        }
        sum += num;
      }

      cnt > k ? left = middle + 1 : right = middle;
    }
    return left;
  }
};

} // namespace binary_search

namespace memo {

// Time: O(N^2K)
// Space: O(NK)
class Solution {
public:
  static int splitArray(const std::vector<int> &nums, int k) {
    std::vector<int> ps(nums.size() + 1);
    std::partial_sum(nums.begin(), nums.end(), ps.begin() + 1);
    std::vector memo(nums.size() + 1, std::vector<int>(k + 1, -1));
    return splitArray(nums.size(), k, ps, &memo);
  }

private:
  static int splitArray(int i, int k, const std::vector<int> &ps,
                        std::vector<std::vector<int>> *memo) {
    if (k == 1) {
      return ps[i];
    }
    auto &ans = (*memo)[i][k];
    if (ans == -1) {
      ans = INT_MAX;
      for (int j = k - 1; j < i; ++j) {
        const auto sum =
            std::max(ps[i] - ps[j], splitArray(j, k - 1, ps, memo));
        ans = std::min(ans, sum);
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2K)
// Space: O(NK)
class Solution {
public:
  static int splitArray(const std::vector<int> &nums, int k) {
    const int n = nums.size();

    std::vector<int> ps(n + 1);
    std::partial_sum(nums.begin(), nums.end(), ps.begin() + 1);

    std::vector dp(n + 1, std::vector<int>(k + 1, -1));
    for (int i = 1; i <= n; ++i) {
      dp[i][1] = ps[i];
    }

    for (int l = 2; l <= k; ++l) {
      for (int i = 1; i <= n; ++i) {
        dp[i][l] = INT_MAX;
        for (int j = l - 1; j < i; ++j) {
          dp[i][l] = std::min(dp[i][l], std::max(ps[i] - ps[j], dp[j][l - 1]));
        }
      }
    }
    return dp[n][k];
  }
};

} // namespace dp
