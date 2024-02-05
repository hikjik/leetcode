#pragma once

#include <array>
#include <string>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static int firstUniqChar(std::string s) {
    std::array<int, 128> counter{};
    for (auto c : s) {
      ++counter[c];
    }
    for (int i = 0; i < std::ssize(s); ++i) {
      if (counter[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
