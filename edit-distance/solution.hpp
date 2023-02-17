#pragma once

#include <string>
#include <vector>

class Solution {
private:
  static const size_t MAX_LENGTH = 500;
  inline static int DP[MAX_LENGTH + 1][MAX_LENGTH + 1];

public:
  static int minDistance(std::string word1, std::string word2) {
    size_t n = word1.size();
    size_t m = word2.size();

    for (size_t i = 0; i <= n; ++i) {
      DP[i][0] = i;
    }
    for (size_t j = 0; j <= m; ++j) {
      DP[0][j] = j;
    }

    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j <= m; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          DP[i][j] = DP[i - 1][j - 1];
        } else {
          DP[i][j] =
              1 + std::min({DP[i - 1][j - 1], DP[i][j - 1], DP[i - 1][j]});
        }
      }
    }

    return DP[n][m];
  }
};
