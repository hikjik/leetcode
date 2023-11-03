#pragma once

#include <numeric>
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
  static int minDistance(std::string word1, std::string word2) {
    std::vector memo(word1.size() + 1, std::vector<int>(word2.size() + 1, -1));
    return minDistance(std::string_view(word1), std::string_view(word2), &memo);
  }

private:
  static int minDistance(std::string_view word1, std::string_view word2,
                         std::vector<std::vector<int>> *memo) {
    if (word1.empty() || word2.empty()) {
      return std::max(word1.size(), word2.size());
    }

    auto &distance = (*memo)[word1.size()][word2.size()];
    if (distance != -1) {
      return distance;
    }

    if (word1[0] == word2[0]) {
      distance = minDistance(word1.substr(1), word2.substr(1), memo);
    } else {
      const auto insert = minDistance(word1, word2.substr(1), memo);
      const auto remove = minDistance(word1.substr(1), word2, memo);
      const auto replace = minDistance(word1.substr(1), word2.substr(1), memo);
      distance = 1 + std::min({insert, remove, replace});
    }
    return distance;
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int minDistance(std::string word1, std::string word2) {
    const int n = word1.size(), m = word2.size();

    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] =
              1 + std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
      }
    }

    return dp[n][m];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(min(N, M))
class Solution {
public:
  static int minDistance(const std::string &word1, const std::string &word2) {
    const int n = word1.size(), m = word2.size();
    if (m > n) {
      return minDistance(word2, word1);
    }

    std::vector<int> dp(m + 1);
    std::iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i <= n; ++i) {
      auto prev = dp[0];
      dp[0] = i;
      for (int j = 1; j <= m; ++j) {
        std::swap(prev, dp[j]);
        if (word1[i - 1] != word2[j - 1]) {
          dp[j] = 1 + std::min({prev, dp[j - 1], dp[j]});
        }
      }
    }
    return dp[m];
  }
};

} // namespace optimized
