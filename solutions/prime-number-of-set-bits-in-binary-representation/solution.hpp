#pragma once

#include <unordered_set>

// Time:
// Space:

class Solution {
public:
  static int countPrimeSetBits(int left, int right) {
    std::unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
    int cnt = 0;
    for (int i = left; i <= right; ++i) {
      if (primes.contains(__builtin_popcount(i))) {
        ++cnt;
      }
    }
    return cnt;
  }
};
