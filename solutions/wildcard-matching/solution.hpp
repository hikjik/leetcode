#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <vector>

// Time: O(NM)
// Space: O(1)

void removeAdjacentAsterisk(std::string &s) {
  int i = 0;
  for (int j = 0; j < std::ssize(s); ++j) {
    if (s[j] != '*' || !j || s[j - 1] != '*') {
      s[i++] = s[j];
    }
  }
  s.resize(i);
}

namespace memoization {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    removeAdjacentAsterisk(p);
    std::vector memo(s.size() + 1, std::vector<char>(p.size() + 1, -1));
    return isMatch(std::string_view(s), std::string_view(p), &memo);
  }

private:
  static bool isMatch(std::string_view s, std::string_view p,
                      std::vector<std::vector<char>> *memo) {
    if (p.empty()) {
      return s.empty();
    }

    auto &match = (*memo)[s.size()][p.size()];
    if (match != -1) {
      return match;
    }

    if (s.empty()) {
      match = std::ranges::all_of(p, [](char c) { return c == '*'; });
    } else if (s[0] == p[0] || p[0] == '?') {
      match = isMatch(s.substr(1), p.substr(1), memo);
    } else if (p[0] == '*') {
      match = isMatch(s, p.substr(1), memo) || isMatch(s.substr(1), p, memo);
    } else {
      match = false;
    }
    return match;
  }
};

} // namespace memoization

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    removeAdjacentAsterisk(p);
    const int n = s.size(), m = p.size();

    std::vector dp(n + 1, std::vector<bool>(m + 1));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
      dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }

    return dp[n][m];
  }
};

} // namespace dp

namespace greedy {

// Time: O(NM)
// Space: O(1)
class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    removeAdjacentAsterisk(p);
    const int n = s.size(), m = p.size();

    int i = 0, j = 0;
    int last_asterisk = -1, last_match = 0;
    while (i < n) {
      if (j < m && s[i] == p[j] || p[j] == '?') {
        ++i, ++j;
      } else if (j < m && p[j] == '*') {
        last_match = i;
        last_asterisk = j++;
      } else if (last_asterisk != -1) {
        j = last_asterisk + 1;
        i = ++last_match;
      } else {
        return false;
      }
    }
    return std::all_of(p.begin() + j, p.end(), [](char c) { return c == '*'; });
  }
};

} // namespace greedy
