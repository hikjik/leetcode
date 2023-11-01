#pragma once

/*
  1611. Minimum One Bit Operations to Make Integers Zero
  https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
  Difficulty: Hard
  Tags: Dynamic Programming, Bit Manipulation, Memoization
  Time:
  Space:
*/

class Solution {
public:
  static int minimumOneBitOperations(int n) { return GrayCodeToBinary(n); }

private:
  static int GrayCodeToBinary(int n) {
    int res = n;
    while (n) {
      n >>= 1;
      res ^= n;
    }
    return res;
  }
};
