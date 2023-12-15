#pragma once

#include <array>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::string originalDigits(std::string s) {
    std::array<int, 10> cnt{};
    for (auto c : s) {
      if (c == 'z') {
        ++cnt[0];
      } else if (c == 'o') {
        ++cnt[1]; // 1 0 2 4
      } else if (c == 'w') {
        ++cnt[2];
      } else if (c == 'h') {
        ++cnt[3]; // 3 8
      } else if (c == 'u') {
        ++cnt[4];
      } else if (c == 'f') {
        ++cnt[5]; // 5 4
      } else if (c == 'x') {
        ++cnt[6];
      } else if (c == 's') {
        ++cnt[7]; // 7 6
      } else if (c == 'g') {
        ++cnt[8];
      } else if (c == 'i') {
        ++cnt[9]; // 9 5 6 8
      }
    }

    cnt[3] -= cnt[8];
    cnt[5] -= cnt[4];
    cnt[1] -= cnt[0] + cnt[2] + cnt[4];
    cnt[7] -= cnt[6];
    cnt[9] -= cnt[5] + cnt[6] + cnt[8];

    std::string ans;
    for (int i = 0; i < 10; ++i) {
      while (cnt[i]--) {
        ans += '0' + i;
      }
    }
    return ans;
  }
};
