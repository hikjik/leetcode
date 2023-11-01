#pragma once

#include <climits>

/*
  7. Reverse Integer
  https://leetcode.com/problems/reverse-integer/
  Difficulty: Medium
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int reverse(int n) {
    int ans = 0;
    while (n) {
      const auto r = n % 10;
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
        return 0;
      }
      ans = ans * 10 + r;
      n /= 10;
    }
    return ans;
  }
};
