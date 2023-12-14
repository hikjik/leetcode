#pragma once

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static bool checkPowersOfThree(int n) {
    while (n > 1) {
      if (n % 3 == 2) {
        return false;
      }
      n /= 3;
    }
    return true;
  }
};
