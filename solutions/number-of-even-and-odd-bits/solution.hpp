#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> evenOddBit(int n) {
    std::vector<int> ans(2);
    for (int i = 0; n; ++i, n >>= 1) {
      if (n & 1) {
        ++ans[i & 1];
      }
    }
    return ans;
  }
};
