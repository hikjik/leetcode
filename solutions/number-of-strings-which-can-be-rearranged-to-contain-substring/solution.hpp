#pragma once

#include <string>

// Time: O(logN)
// Space: O(1)
// Notes: [Inclusion–exclusion principle](https://w.wiki/Dna)

// S = {s: s.size() == n }
// A = {s in S : s.count('l')  == 0}
// B = {s in S : s.count('l')  == 0}
// C = {s in S : s.count('l')  == 0}
// ans = |S| - |A| - |B| - |C| + |AB| + |AC| + |BC| - |ABC|
//     = |S| - 2|A| -|B| + 2|AB| + |AC| - |ABC|
class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

  static int mul(long long a, long long b, int mod = kMod) {
    return a * b % mod;
  }

  static int pow(int a, int b, int mod = kMod) {
    int res = 1;
    for (; b; b >>= 1) {
      if (b & 1) {
        res = mul(res, a, mod);
      }
      a = mul(a, a, mod);
    }
    return res;
  }

public:
  static int stringCount(int n) {
    const auto ans = 0LL + pow(26, n) - mul(75 + n, pow(25, n - 1)) +
                     mul(72 + 2 * n, pow(24, n - 1)) -
                     mul(23 + n, pow(23, n - 1));
    return (ans % kMod + kMod) % kMod;
  }
};
