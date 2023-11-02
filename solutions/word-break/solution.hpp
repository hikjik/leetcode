#pragma once

#include <string>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool wordBreak(const std::string &str,
                        const std::vector<std::string> &word_list) {
    std::unordered_set<std::string> word_dict{word_list.begin(),
                                              word_list.end()};

    std::vector<bool> dp(str.size() + 1, false);
    dp[0] = true;
    for (size_t i = 1; i <= str.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (dp[j] && word_dict.count(str.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};
