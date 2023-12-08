#pragma once

#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

namespace dp {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static int deleteString(std::string s) {
    const int n = s.size();

    std::vector lcs(n + 1, std::vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= i + 1; --j) {
        if (s[i] == s[j]) {
          lcs[i][j] = 1 + lcs[i + 1][j + 1];
        }
      }
    }

    std::vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= i + 1; --j) {
        if (lcs[i][j] >= j - i) {
          dp[i] = std::max(dp[i], 1 + dp[j]);
        }
      }
    }
    return dp[0];
  }
};

} // namespace dp

namespace optimized {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int deleteString(std::string s) {
    const int n = s.size();
    std::vector<int> lcs(n + 1);
    std::vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        lcs[j] = s[i] == s[j] ? 1 + lcs[j + 1] : 0;
        if (lcs[j] >= j - i) {
          dp[i] = std::max(dp[i], 1 + dp[j]);
        }
      }
    }
    return dp[0];
  }
};

} // namespace optimized
