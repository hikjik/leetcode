#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
private:
  std::unordered_map<std::string, bool> dp;

public:
  bool isScramble(std::string s1, std::string s2) {
    if (s1 == s2) {
      return true;
    }
    auto key = s1 + "#" + s2;
    if (auto it = dp.find(key); it != dp.end()) {
      return it->second;
    }

    int n = s1.size();
    std::vector<int> cnt(128, 0);
    for (int i = 0; i < n; ++i) {
      cnt[s1[i]]++, cnt[s2[i]]--;
    }
    for (auto c : cnt) {
      if (c != 0) {
        return dp[key] = false;
      }
    }

    for (int i = 1; i < n; ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i))) {
        return dp[key] = true;
      }

      if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
          isScramble(s1.substr(i), s2.substr(0, n - i))) {
        return dp[key] = true;
      }
    }
    return dp[key] = false;
  }
};
