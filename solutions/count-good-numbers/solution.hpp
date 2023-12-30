#pragma once

// Time:
// Space:

class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int mul(long long a, long long b, int mod = kMod) {
    return a * b % mod;
  }

  static int pow(int a, long long b, int mod = kMod) {
    int res = 1;
    for (; b; b >>= 1) {
      if (b & 1) {
        res = mul(res, a, mod);
      }
      a = mul(a, a, mod);
    }
    return res;
  }

  static int countGoodNumbers(long long n) {
    return mul(pow(5, (n + 1) / 2), pow(4, n / 2));
  }
};
