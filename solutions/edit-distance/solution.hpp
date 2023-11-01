#pragma once

#include <string>
#include <vector>

/*
  72. Edit Distance
  https://leetcode.com/problems/edit-distance/
  Difficulty: Medium
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
private:
  static constexpr size_t kMaxLength = 500;
  inline static int DP[kMaxLength + 1][kMaxLength + 1];

public:
  static int minDistance(std::string word1, std::string word2) {
    const auto n = word1.size(), m = word2.size();

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
