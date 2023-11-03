#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static const int kMod = 1e9 + 7;
  static const int kAlphabet = 26;

public:
  static int numWays(const std::vector<std::string> &words,
                     std::string target) {
    const int k = words.back().size();
    std::vector<std::vector<int>> cnt(kAlphabet, std::vector<int>(k, 0));
    for (const auto &word : words) {
      for (int j = 0; j < k; ++j) {
        cnt[word[j] - 'a'][j]++;
      }
    }

    const int m = target.size();
    std::vector<std::vector<long long>> dp(m + 1,
                                           std::vector<long long>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < k; j++) {
        if (i < m) {
          dp[i + 1][j + 1] += cnt[target[i] - 'a'][j] * dp[i][j];
          dp[i + 1][j + 1] %= kMod;
        }
        dp[i][j + 1] += dp[i][j];
        dp[i][j + 1] %= kMod;
      }
    }
    return dp[m][k];
  }
};
