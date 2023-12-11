#pragma once

#include <ranges>
#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace memo {

// Time: O(ND)
// Space: O(N)
class Solution {
public:
  static int maxJumps(const std::vector<int> &arr, int d) {
    std::vector<int> memo(arr.size(), 0);
    for (int i = 0; i < std::ssize(arr); ++i) {
      maxJumps(i, arr, d, &memo);
    }
    return std::ranges::max(memo);
  }

private:
  static int maxJumps(int i, const std::vector<int> &arr, int d,
                      std::vector<int> *memo) {
    const int n = arr.size();
    auto &ans = (*memo)[i];
    if (!ans) {
      ans = 1;
      for (int j = i + 1; j <= std::min(i + d, n - 1) && arr[j] < arr[i]; ++j) {
        ans = std::max(ans, 1 + maxJumps(j, arr, d, memo));
      }
      for (int j = i - 1; j >= std::max(0, i - d) && arr[j] < arr[i]; --j) {
        ans = std::max(ans, 1 + maxJumps(j, arr, d, memo));
      }
    }
    return ans;
  }
};

} // namespace memo

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int maxJumps(const std::vector<int> &arr, int d) {
    const int n = arr.size();
    std::vector<int> dp(n, 1);
    std::stack<int> stack;
    for (int i = 0; i <= n; ++i) {
      while (!stack.empty() && (i == n || arr[stack.top()] < arr[i])) {
        const auto top = arr[stack.top()];
        std::vector<int> idx;
        while (!stack.empty() && top == arr[stack.top()]) {
          idx.push_back(stack.top());
          stack.pop();
        }

        for (auto j : idx) {
          if (i < n && i - j <= d) {
            dp[i] = std::max(dp[i], dp[j] + 1);
          }
          if (!stack.empty()) {
            const auto k = stack.top();
            if (j - k <= d) {
              dp[k] = std::max(dp[k], dp[j] + 1);
            }
          }
        }
      }
      stack.push(i);
    }
    return std::ranges::max(dp);
  }
};

} // namespace stack
