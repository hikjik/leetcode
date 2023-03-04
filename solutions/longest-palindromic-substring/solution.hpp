#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string longestPalindrome(std::string s) {
    std::vector<std::vector<bool>> dp(s.size(),
                                      std::vector<bool>(s.size(), false));
    std::pair<size_t, size_t> sub{0, 0};
    for (size_t k = 0; k < s.size(); ++k) {
      for (size_t i = 0; i < s.size() - k; ++i) {
        dp[i][i + k] = (k > 1 ? dp[i + 1][i + k - 1] : true) & s[i] == s[i + k];
        if (dp[i][i + k] && k + 1 > sub.second) {
          sub = {i, k + 1};
        }
      }
    }
    return s.substr(sub.first, sub.second);
  }
};
