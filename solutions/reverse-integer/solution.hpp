#pragma once

#include <climits>

class Solution {
public:
  static int reverse(int x) {
    int res = 0;
    while (x) {
      int d = x % 10;
      if (res > INT_MAX / 10 || res == INT_MAX / 10 && d > 7) {
        return 0;
      }
      if (res < INT_MIN / 10 || res == INT_MIN / 10 && d < -8) {
        return 0;
      }
      res = res * 10 + d;
      x /= 10;
    }
    return res;
  }
};
