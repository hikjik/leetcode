#pragma once

// Time: O(logN)
// Space: O(logN)

class Solution {
public:
  static int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
  }
};
