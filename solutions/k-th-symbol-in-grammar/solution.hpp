#pragma once

// Time:
// Space:

class Solution {
public:
  static int kthGrammar(int n, int k) {
    return n == 1 ? 0 : ((k - 1) & 1) ^ kthGrammar(n - 1, ((k - 1) >> 1) + 1);
  }
};
