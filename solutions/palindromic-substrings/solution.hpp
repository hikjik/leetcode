#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)
// Notes: [Manacher's Algorithm](https://cp-algorithms.com/string/manacher.html)

namespace memo {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static int countSubstrings(std::string s) {
    const int n = s.size();

    std::vector memo(n, std::vector<char>(n, -1));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        ans += isPalindromic(i, j, s, &memo);
      }
    }
    return ans;
  }

private:
  static bool isPalindromic(int i, int j, const std::string &s,
                            std::vector<std::vector<char>> *memo) {
    if (i >= j) {
      return true;
    }
    auto &ans = (*memo)[i][j];
    if (ans == -1) {
      ans = s[i] == s[j] && isPalindromic(i + 1, j - 1, s, memo);
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static int countSubstrings(std::string s) {
    const int n = s.size();
    int ans = 0;
    std::vector dp(n, std::vector<bool>(n));
    for (int k = 0; k < n; ++k) {
      for (int i = 0, j = i + k; j < n; ++i, ++j) {
        dp[i][j] = s[i] == s[j] && (k < 2 || dp[i + 1][j - 1]);
        ans += dp[i][j];
      }
    }
    return ans;
  }
};

} // namespace dp

namespace expand {

// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  static int countSubstrings(std::string s) {
    const int n = s.size();

    auto expand = [&](int i, int j) {
      while (i >= 0 && j < n && s[i] == s[j]) {
        --i, ++j;
      }
      return j - i - 1;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += expand(i, i + 1) / 2 + expand(i, i) / 2 + 1;
    }
    return ans;
  }
};

} // namespace expand

namespace manacher {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int countSubstrings(std::string s) {
    int ans = 0;
    for (auto d : manacher(s)) {
      ans += d / 2;
    }
    return ans;
  }

private:
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
