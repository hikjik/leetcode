#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static bool isFascinating(int n) {
    auto s = std::to_string(n) + std::to_string(2 * n) + std::to_string(3 * n);
    std::sort(s.begin(), s.end());
    return s == "123456789";
  }
};
