#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::string oddString(const std::vector<std::string> &words) {
    const int n = words.size(), m = words.back().size();

    for (int j = 1; j < m; ++j) {
      for (int i = 2; i < n; ++i) {
        if (words[i][j] - words[i][j - 1] !=
            words[i - 1][j] - words[i - 1][j - 1]) {
          if (words[i][j] - words[i][j - 1] ==
              words[i - 2][j] - words[i - 2][j - 1]) {
            return words[i - 1];
          } else {
            return words[i];
          }
        }
        if (words[i][j] - words[i][j - 1] !=
            words[i - 2][j] - words[i - 2][j - 1]) {
          if (words[i][j] - words[i][j - 1] ==
              words[i - 1][j] - words[i - 1][j - 1]) {
            return words[i - 2];
          } else {
            return words[i];
          }
        }
      }
    }

    throw;
  }
};
