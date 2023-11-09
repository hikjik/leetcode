#pragma once

#include <climits>
#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N)

namespace dp {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static int minCut(std::string s) {
    const int n = s.size();

    std::vector pal(n, std::vector<bool>(n));
    for (int k = 0; k < n; ++k) {
      for (int i = 0, j = i + k; j < n; ++i, ++j) {
        pal[i][j] = s[i] == s[j] && (k < 2 || pal[i + 1][j - 1]);
      }
    }

    std::vector<int> dp(n, n);
    for (int i = 0; i < n; ++i) {
      if (pal[0][i]) {
        dp[i] = 0;
      } else {
        for (int j = 0; j < i; ++j) {
          if (pal[j + 1][i]) {
            dp[i] = std::min(dp[i], 1 + dp[j]);
          }
        }
      }
    }
    return dp[n - 1];
  }
};

} // namespace dp

namespace manacher {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int minCut(std::string s) {
    const int n = s.size();
    const auto p = manacher(s);

    std::vector<int> dp(n, n);
    for (int i = 0; i < n; ++i) {
      if (isPalindrome(0, i, p)) {
        dp[i] = 0;
      } else {
        for (int j = 0; j < i; ++j) {
          if (isPalindrome(j + 1, i, p)) {
            dp[i] = std::min(dp[i], 1 + dp[j]);
          }
        }
      }
    }
    return dp[n - 1];
  }

private:
  static bool isPalindrome(int i, int j, const std::vector<int> &p) {
    return p[i + j + 2] - 1 >= j - i + 1;
  }

  static std::vector<int> manacher(const std::string &s) {
    std::string t = "^";
    for (auto c : s) {
      t += '#', t += c;
    }
    t += '#', t += '$';

    std::vector<int> p(t.size());
    for (int i = 1, l = 1, r = 1; i < std::ssize(t) - 1; ++i) {
      const int j = l + r - i;
      p[i] = std::max(0, std::min(r - i, p[j]));

      while (t[i - p[i]] == t[i + p[i]]) {
        ++p[i];
      }

      if (i + p[i] > r) {
        l = i - p[i], r = i + p[i];
      }
    }
    return p;
  }
};

} // namespace manacher
