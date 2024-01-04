#pragma once

#include <array>
#include <cmath>
#include <string>

// Time: O(N+A)
// Space: O(A)

class Solution {
public:
  static int calculateTime(std::string keyboard, std::string word) {
    std::array<int, 26> pos;
    for (int i = 0; auto c : keyboard) {
      pos[c - 'a'] = i++;
    }

    int ans = 0;
    for (int i = 0; auto c : word) {
      const int j = pos[c - 'a'];
      ans += std::abs(i - j);
      i = j;
    }
    return ans;
  }
};
