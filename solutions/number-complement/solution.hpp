#pragma once

class Solution {
public:
  static int findComplement(int num) {
    return ((1LL << (32 - __builtin_clz(num))) - 1) ^ num;
  }
};
