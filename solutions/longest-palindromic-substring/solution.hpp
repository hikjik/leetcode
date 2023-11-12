#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <vector>

// Time: O(N)
// Space: O(N)
// Notes: [Manacher's Algorithm](https://cp-algorithms.com/string/manacher.html)

namespace dp {

// Time: O(N^2)
// Space: O(N^2)
// Dynamic Programming
class Solution {
public:
  static std::string longestPalindrome(std::string s) {
    const int n = s.size();
    std::string_view sv(s);

    auto palindrome = sv.substr(0, 0);
    std::vector dp(n, std::vector<bool>(n));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      palindrome = sv.substr(i, 1);
    }

    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        palindrome = sv.substr(i, 2);
      }
    }

    for (int k = 2; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        if (s[i] == s[i + k]) {
          dp[i][i + k] = dp[i + 1][i + k - 1];
        }
        if (dp[i][i + k]) {
          palindrome = sv.substr(i, k + 1);
        }
      }
    }

    return std::string(palindrome);
  }
};

} // namespace dp

namespace optimized {

// Time: O(N^2)
// Space: O(1)
// Expand From Center
class Solution {
public:
  static std::string longestPalindrome(std::string s) {
    const int n = s.size();
    std::string_view sv(s);

    auto expand = [&](int i, int j) {
      while (i >= 0 && j < n && sv[i] == sv[j]) {
        --i, ++j;
      }
      return sv.substr(i + 1, j - i - 1);
    };

    auto palindrome = sv.substr(0, 0);
    for (int i = 0; i < n; ++i) {
      const auto odd = expand(i, i);
      if (odd.size() > palindrome.size()) {
        palindrome = odd;
      }

      const auto even = expand(i, i + 1);
      if (even.size() > palindrome.size()) {
        palindrome = even;
      }
    }

    return std::string(palindrome);
  }
};

} // namespace optimized

namespace manacher {

// Time: O(N)
// Space: O(N)
// Manacher's Algo
class Solution {
public:
  static std::string longestPalindrome(std::string s) {
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

    const auto c = std::ranges::max_element(p) - p.begin();
    const auto l = (c - p[c]) / 2, r = (c + p[c]) / 2;
    return s.substr(l, r - l - 1);
  }
};

} // namespace manacher
