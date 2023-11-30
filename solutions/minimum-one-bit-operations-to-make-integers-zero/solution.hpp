#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int minimumOneBitOperations(int n) { return grayCodeToBinary(n); }

private:
  static int grayCodeToBinary(int n) {
    int res = n;
    while (n) {
      n >>= 1;
      res ^= n;
    }
    return res;
  }
};
