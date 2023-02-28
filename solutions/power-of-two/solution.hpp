#pragma once

class Solution {
public:
  static bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); };
};
