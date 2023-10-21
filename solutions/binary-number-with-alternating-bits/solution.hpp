#pragma once

class Solution {
public:
  static bool hasAlternatingBits(int n) {
    n ^= n >> 2;
    return !(n & (n - 1));
  }
};
