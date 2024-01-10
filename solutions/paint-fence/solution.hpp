#pragma once

#include <utility>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  // numWays(n) = lastTwoSame(n) + lastTwoDiff(n)
  // lastTwoSame(n) = lastTwoDiff(n - 1)
  // lastTwoDiff(n) = numWays(n - 1) * (k - 1)
  // numWays(n) = lastTwoSame(n) + lastTwoDiff(n)
  //            = lastTwoDiff(n - 1) + numWays(n - 1) * (k - 1)
  //            = numWays(n - 2) * (k - 1) + numWays(n - 1) * (k - 1)
  // numWays(1) = k, numWays(2) = k * k
  static int numWays(int n, int k) {
    if (n == 1) {
      return k;
    }
    int a = k, b = k * k;
    for (int i = 2; i < n; ++i) {
      a = std::exchange(b, (a + b) * (k - 1));
    }
    return b;
  }
};
