#pragma once

class Solution {
public:
  static int bitwiseComplement(int n) {
    return n ? ((1 << (32 - __builtin_clz(n))) - 1) ^ n : 1;
  }
};
