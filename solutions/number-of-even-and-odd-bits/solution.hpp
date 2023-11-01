#pragma once

#include <vector>

/*
  2595. Number of Even and Odd Bits
  https://leetcode.com/problems/number-of-even-and-odd-bits/
  Difficulty: Easy
  Tags: Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> evenOddBit(int n) {
    std::vector<int> ans(2);
    for (int i = 0; n; ++i, n >>= 1) {
      if (n & 1) {
        ++ans[i & 1];
      }
    }
    return ans;
  }
};
