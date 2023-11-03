#pragma once

#include "api.hpp"

// Time:
// Space:

class Solution {
public:
  static int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
      int middle = left + (right - left) / 2;
      if (isBadVersion(middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return left;
  }
};
