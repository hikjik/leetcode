#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int captureForts(const std::vector<int> &forts) {
    int ans = 0;
    for (int i = 0, j = 0; j < std::ssize(forts); ++j) {
      if (forts[j]) {
        if (forts[i] == -forts[j]) {
          ans = std::max(ans, j - i - 1);
        }
        i = j;
      }
    }
    return ans;
  }
};
