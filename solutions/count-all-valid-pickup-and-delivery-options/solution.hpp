#pragma once

// Time:
// Space:

class Solution {
public:
  static const int kMod = 1e9 + 7;

  static int countOrders(int n) {
    long long cnt = 1;
    for (int i = 1; i <= n; ++i) {
      cnt = cnt * (2 * i - 1) * i % kMod;
    }
    return cnt;
  }
};
