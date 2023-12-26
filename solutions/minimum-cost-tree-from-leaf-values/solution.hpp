#pragma once

#include <climits>
#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace dp {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int mctFromLeafValues(const std::vector<int> &arr) {
    const int n = arr.size();
    std::vector max(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      max[i][i] = arr[i];
    }
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        max[i][i + k] = std::max(max[i][i], max[i + 1][i + k]);
      }
    }

    std::vector dp(n, std::vector<int>(n));
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        dp[i][i + k] = INT_MAX;
        for (int j = i; j < i + k; ++j) {
          dp[i][i + k] =
              std::min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] +
                                         max[i][j] * max[j + 1][i + k]);
        }
      }
    }
    return dp[0][n - 1];
  }
};

} // namespace dp

namespace greedy {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int mctFromLeafValues(std::vector<int> arr) {
    int ans = 0;
    while (arr.size() > 1) {
      int i = 0;
      for (int j = 0; j + 1 < std::ssize(arr); ++j) {
        if (arr[j] * arr[j + 1] < arr[i] * arr[i + 1]) {
          i = j;
        }
      }
      ans += arr[i] * arr[i + 1];
      arr[i] = std::max(arr[i], arr[i + 1]);
      arr.erase(arr.begin() + i + 1);
    }
    return ans;
  }
};

} // namespace greedy

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int mctFromLeafValues(const std::vector<int> &arr) {
    std::stack<int> stack;
    int ans = 0;
    for (auto num : arr) {
      while (!stack.empty() && stack.top() <= num) {
        const auto top = stack.top();
        stack.pop();

        ans += top * std::min(stack.empty() ? num : stack.top(), num);
      }
      stack.push(num);
    }
    while (stack.size() > 1) {
      const auto top = stack.top();
      stack.pop();
      ans += top * stack.top();
    }
    return ans;
  }
};

} // namespace stack
