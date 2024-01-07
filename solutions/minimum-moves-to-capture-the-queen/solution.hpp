#pragma once

#include <algorithm>

// Time: O(1)
// Space: O(1)

class Solution {
public:
  static int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e,
                                       int f) {
    auto between = [](int a, int l, int r) {
      return std::min(l, r) < a && a < std::max(l, r);
    };
    if (a == e && !(a == c && between(d, b, f))) {
      return 1;
    }
    if (b == f && !(b == d && between(c, a, e))) {
      return 1;
    }
    if (c + d == e + f && !(c + d == a + b && between(a, c, e))) {
      return 1;
    }
    if (c - d == e - f && !(c - d == a - b && between(a, c, e))) {
      return 1;
    }
    return 2;
  }
};
