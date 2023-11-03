#pragma once

// Time:
// Space:

class Solution {
public:
  static int minFlips(int a, int b, int c) {
    return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ~c);
  }
};
