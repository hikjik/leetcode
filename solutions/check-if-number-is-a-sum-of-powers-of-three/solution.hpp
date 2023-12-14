#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static bool checkPowersOfThree(int n) {
    for (; n > 1; n /= 3) {
      if (n % 3 == 2) {
        return false;
      }
    }
    return true;
  }
};
