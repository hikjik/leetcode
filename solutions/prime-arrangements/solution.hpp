#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

public:
  static int numPrimeArrangements(int n) {
    const auto cnt = countPrimes(n);
    return factorial(cnt) * factorial(n - cnt) % kMod;
  }

private:
  static int countPrimes(int n) {
    static const std::vector<int> primes{2,  3,  5,  7,  11, 13, 17, 19, 23,
                                         29, 31, 37, 41, 43, 47, 53, 59, 61,
                                         67, 71, 73, 79, 83, 89, 97};
    return std::upper_bound(primes.begin(), primes.end(), n) - primes.begin();
  }

  static long long factorial(int n) {
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
      ans = ans * i % kMod;
    }
    return ans;
  }
};
