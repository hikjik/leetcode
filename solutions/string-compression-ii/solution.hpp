#pragma once

#include <array>
#include <string>
#include <string_view>
#include <vector>

// Time: O(N^2K)
// Space: O(NK)

namespace memo {

// Time: O(N^2K)
// Space: O(NK)
class Solution {
public:
  static int getLengthOfOptimalCompression(std::string s, int k) {
    std::vector memo(s.size() + 1, std::vector<int>(k + 1, kInf));
    return getLength(s, k, &memo);
  }

private:
  static constexpr int kInf = 101;

  static int getLength(std::string_view s, int k,
                       std::vector<std::vector<int>> *memo) {
    if (k < 0) {
      return kInf;
    }
    if (s.empty() || std::ssize(s) <= k) {
      return 0;
    }
    auto &ans = (*memo)[s.size()][k];
    if (ans == kInf) {
      int mostFreq = 0;
      std::array<int, 26> cnt{};
      for (int j = 0; j < std::ssize(s); ++j) {
        mostFreq = std::max(mostFreq, ++cnt[s[j] - 'a']);
        ans = std::min(
            ans, getLength(mostFreq) +
                     getLength(s.substr(j + 1), k - (j + 1 - mostFreq), memo));
      }
    }
    return ans;
  }

  static int getLength(int f) {
    return f == 1 ? 1 : f < 10 ? 2 : f < 100 ? 3 : 4;
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2K)
// Space: O(NK)
class Solution {
public:
  static int getLengthOfOptimalCompression(std::string s, int k) {
    const int n = s.size();
    std::vector dp(n + 1, std::vector<int>(k + 1));

    for (int i = n - 1; i >= 0; --i) {
      for (int t = 0; t <= k; ++t) {
        // delete ith char
        dp[i][t] = t > 0 ? dp[i + 1][t - 1] : INT_MAX;

        // keep ith char
        int cnt = 0;
        for (int j = i; j < n; ++j) {
          cnt += s[i] == s[j];
          const auto s = t - (j + 1 - i - cnt);
          if (s < 0) {
            break;
          }
          dp[i][t] = std::min(dp[i][t], getLength(cnt) + dp[j + 1][s]);
        }
      }
    }
    return dp[0][k];
  }

private:
  static int getLength(int f) {
    return f == 1 ? 1 : f < 10 ? 2 : f < 100 ? 3 : 4;
  }
};

} // namespace dp
