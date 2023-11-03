#pragma once

// Time:
// Space:

class Solution {
public:
  static int sumOfMultiples(int n) {
    return count(n, 3) + count(n, 5) + count(n, 7) - count(n, 3 * 5) -
           count(n, 3 * 7) - count(n, 5 * 7) + count(n, 3 * 5 * 7);
  }

private:
  static int count(int n, int d) { return d * (1 + n / d) * (n / d) / 2; }
};
