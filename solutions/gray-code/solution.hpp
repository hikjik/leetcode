#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> grayCode(int n) {
    std::vector<int> code(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
      code[i] = i ^ (i >> 1);
    }
    return code;
  }
};
