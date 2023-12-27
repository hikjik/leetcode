#pragma once

#include <string>
#include <vector>

// Time: O(N^2)
// Space: O(N)

namespace dp {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static bool checkPartitioning(std::string s) {
    const int n = s.size();

    std::vector dp(n, std::vector<bool>(n));
    for (int k = 0; k < n; ++k) {
      for (int i = 0, j = i + k; j < n; ++i, ++j) {
        dp[i][j] = s[i] == s[j] && (k < 2 || dp[i + 1][j - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (!dp[0][i]) {
        continue;
      }
      for (int j = i + 1; j + 1 < n; ++j) {
        if (dp[i + 1][j] && dp[j + 1][n - 1]) {
          return true;
        }
      }
    }
    return false;
  }
};

} // namespace dp

namespace manacher {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static bool checkPartitioning(std::string s) {
    const int n = s.size();
    const auto p = manacher(s);

    for (int i = 0; i < n; ++i) {
      if (!isPalindrome(0, i, p)) {
        continue;
      }
      for (int j = i + 1; j + 1 < n; ++j) {
        if (isPalindrome(i + 1, j, p) && isPalindrome(j + 1, n - 1, p)) {
          return true;
        }
      }
    }
    return false;
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
