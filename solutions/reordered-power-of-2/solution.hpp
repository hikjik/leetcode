#pragma once

#include <ranges>
#include <string>

// Time: O(logN)
// Space: O(logN)

class Solution {
public:
  static bool reorderedPowerOf2(int n) {
    const auto num = sortedDigits(n);
    for (int i = 0; i < 30; ++i) {
      if (sortedDigits(1 << i) == num) {
        return true;
      }
    }
    return false;
  }

private:
  static std::string sortedDigits(int n) {
    auto num = std::to_string(n);
    std::ranges::sort(num);
    return num;
  }
};
