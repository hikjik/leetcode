#pragma once

#include <regex>
#include <string>
#include <string_view>

// Time: O(NM)
// Space: O(M)

namespace regex {

class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    const std::regex regex(p);
    return std::regex_match(s, regex);
  }
};

} // namespace regex

namespace recursion {

// Time: O((N+M)2^(N+M))
// Space: O(N^2+M^2)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    return isMatch(std::string_view(s), std::string_view(p));
  }

private:
  static bool isMatch(std::string_view s, std::string_view p) {
    if (p.empty()) {
      return s.empty();
    }
    const auto firstMatch = !s.empty() && (p[0] == '.' || p[0] == s[0]);
    if (p.size() > 1 && p[1] == '*') {
      return isMatch(s, p.substr(2)) || firstMatch && isMatch(s.substr(1), p);
    }
    return firstMatch && isMatch(s.substr(1), p.substr(1));
  }
};

} // namespace recursion

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    std::vector memo(s.size() + 1, std::vector<char>(p.size() + 1, -1));
    return isMatch(std::string_view(s), std::string_view(p), &memo);
  }

private:
  static bool isMatch(std::string_view s, std::string_view p,
                      std::vector<std::vector<char>> *memo) {
    if (p.empty()) {
      return s.empty();
    }
    auto &ans = (*memo)[s.size()][p.size()];
    if (ans == -1) {
      const auto firstMatch = !s.empty() && (p[0] == '.' || p[0] == s[0]);
      if (p.size() > 1 && p[1] == '*') {
        ans = isMatch(s, p.substr(2), memo) ||
              firstMatch && isMatch(s.substr(1), p, memo);
      } else {
        ans = firstMatch && isMatch(s.substr(1), p.substr(1), memo);
      }
    }
    return ans;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    const int n = s.size(), m = p.size();

    std::vector dp(n + 1, std::vector<bool>(m + 1));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
      dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (p[j - 1] == '*') {
          if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
            dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
          } else {
            dp[i][j] = dp[i][j - 2];
          }
        } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }

    return dp[n][m];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(M)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    const int n = s.size(), m = p.size();
    std::vector<bool> dp(m + 1);
    dp[0] = true;
    for (int j = 1; j <= m; ++j) {
      dp[j] = p[j - 1] == '*' && dp[j - 2];
    }

    for (int i = 1; i <= n; ++i) {
      bool prev = dp[0];
      dp[0] = false;
      for (int j = 1; j <= m; ++j) {
        bool curr = dp[j];
        if (p[j - 1] == '*') {
          if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
            dp[j] = dp[j] || dp[j - 2];
          } else {
            dp[j] = dp[j - 2];
          }
        } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          dp[j] = prev;
        } else {
          dp[j] = false;
        }
        prev = curr;
      }
    }

    return dp[m];
  }
};

} // namespace optimized
