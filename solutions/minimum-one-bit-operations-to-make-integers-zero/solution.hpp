#pragma once

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
