#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool containsPattern(const std::vector<int> &arr, int m, int k) {
    for (int i = 0, cnt = 0; i + m < std::ssize(arr); ++i) {
      if (arr[i] != arr[i + m]) {
        cnt = 0;
      } else if (++cnt == (k - 1) * m) {
        return true;
      }
    }
    return false;
  }
};
