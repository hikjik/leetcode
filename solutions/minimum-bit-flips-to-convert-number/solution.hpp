#pragma once

class Solution {
public:
  static int minBitFlips(int start, int goal) {
    return __builtin_popcount(start ^ goal);
  }
};
