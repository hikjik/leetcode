#pragma once

// Time:
// Space:

class Solution {
public:
  static int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
};
