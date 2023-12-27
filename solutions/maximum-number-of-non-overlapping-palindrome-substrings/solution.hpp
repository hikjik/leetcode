#pragma once

#include <string>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxPalindromes(std::string s, int k) {
    const int n = s.size();
    const auto p = manacher(s);

    std::vector<int> dp(n + 1);
    for (int i = k; i <= n; ++i) {
      dp[i] = dp[i - 1];
      if (isPalindrome(i - k, i - 1, p)) {
        dp[i] = std::max(dp[i], 1 + dp[i - k]);
      }
      if (i >= k - 1 && isPalindrome(i - k - 1, i - 1, p)) {
        dp[i] = std::max(dp[i], 1 + dp[i - k - 1]);
      }
    }
    return dp.back();
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
