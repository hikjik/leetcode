#pragma once

// Time: O(logM) M = INT_MAX
// Space: O(1)

class Solution {
public:
  static int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left != right) {
      left >>= 1, right >>= 1;
      ++shift;
    }
    return left << shift;
  }
};
