#pragma once

// Time:
// Space:

class Solution {
public:
  static int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;
    while (n) {
      const auto r = n % 10;
      n /= 10;
      product *= r;
      sum += r;
    }
    return product - sum;
  }
};
