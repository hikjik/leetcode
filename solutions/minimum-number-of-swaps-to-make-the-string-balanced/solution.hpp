#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minSwaps(std::string s) {
    int cnt = 0;
    for (auto c : s) {
      if (c == '[') {
        ++cnt;
      } else if (cnt) {
        --cnt;
      }
    }
    return (cnt + 1) / 2;
  }
};
