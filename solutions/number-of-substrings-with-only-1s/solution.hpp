#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numSub(std::string s) {
    long long ans = 0;
    for (int cnt = 0; auto c : s) {
      cnt = c == '0' ? 0 : cnt + 1;
      ans += cnt;
    }
    return ans % kMod;
  }
};
