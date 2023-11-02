#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> ans;
    for (int i = left; i <= right; ++i) {
      if (isSelfDividing(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }

private:
  static bool isSelfDividing(int n) {
    for (int i = n; i; i /= 10) {
      const auto digit = i % 10;
      if (!digit || n % digit != 0) {
        return false;
      }
    }
    return true;
  }
};
