#pragma once

#include <string>
#include <string_view>
#include <vector>

// Time: O(NM)
// Space: O(min(N, M))

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int numDistinct(std::string s, std::string t) {
    std::vector memo(s.size() + 1, std::vector<int>(t.size() + 1, -1));
    return numDistinct(std::string_view(s), std::string_view(t), &memo);
  }

private:
  static int numDistinct(std::string_view s, std::string_view t,
                         std::vector<std::vector<int>> *memo) {
    if (t.empty()) {
      return 1;
    }
    if (s.empty()) {
      return 0;
    }
    auto &cnt = (*memo)[s.size()][t.size()];
    if (cnt == -1) {
      cnt = numDistinct(s.substr(1), t, memo);
      if (s[0] == t[0]) {
        cnt += numDistinct(s.substr(1), t.substr(1), memo);
      }
    }
    return cnt;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int numDistinct(std::string s, std::string t) {
    const int n = s.size(), m = t.size();

    std::vector dp(n + 1, std::vector<unsigned long long>(m + 1));
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][m];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(min(N,M))
class Solution {
public:
  static int numDistinct(std::string s, std::string t) {
    const int n = s.size(), m = t.size();
    if (m > n) {
      std::swap(s, t);
    }

    std::vector<unsigned long long> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = m; j >= 1; --j) {
        if (s[i - 1] == t[j - 1]) {
          dp[j] += dp[j - 1];
        }
      }
    }
    return dp[m];
  }
};

} // namespace optimized
