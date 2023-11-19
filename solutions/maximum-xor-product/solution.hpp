#pragma once

#include <algorithm>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int maximumXorProduct(long long a, long long b, int n) {
    for (int i = n - 1; i >= 0; --i) {
      const auto x = 1LL << i;
      if (!(std::min(a, b) & x)) {
        a ^= x, b ^= x;
      }
    }
    return (a % kMod) * (b % kMod) % kMod;
  }
};
