#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int countHomogenous(std::string s) {
    long long ans = 0;
    int cnt = 0;
    for (auto prev = s[0]; auto curr : s) {
      prev == curr ? ++cnt : cnt = 1;
      prev = curr;
      ans += cnt;
    }
    return ans % kMod;
  }
};
