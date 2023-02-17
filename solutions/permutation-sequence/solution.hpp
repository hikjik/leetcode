#pragma once

#include <string>

class Solution {
public:
  static std::string getPermutation(int n, int k) {
    std::string s;
    for (int i = 1; i <= n; ++i) {
      s += std::to_string(i);
    }
    while (--k) {
      std::next_permutation(s.begin(), s.end());
    }
    return s;
  }
};
