#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static int nextGreaterElement(int n) {
    auto s = std::to_string(n);
    if (std::next_permutation(s.begin(), s.end())) {
      const auto greater = std::stol(s);
      if (greater <= INT_MAX * 1L) {
        return greater;
      }
    }
    return -1;
  }
};
