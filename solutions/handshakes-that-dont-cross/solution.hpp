#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)
// Notes: [Catalan number](https://w.wiki/845b)

namespace dp {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;

  static int numberOfWays(int n) {
    std::vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 2; i <= n; i += 2) {
      for (int j = 0; j < i; j += 2) {
        dp[i] += dp[j] * dp[i - j - 2] % kMod;
      }
      dp[i] %= kMod;
    }
    return dp[n];
  }
};

} // namespace dp

namespace math {

// Time: O(NlogN)
// Space: O(1)
class Solution {
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

  static int inv(int a, int mod = kMod) { return pow(a, mod - 2, mod); }

public:
  static int numberOfWays(int n) {
    int ans = 1;
    for (int i = 1; i <= n / 2; ++i) {
      ans = mul(mul(ans, 4 * i - 2), inv(i + 1));
    }
    return ans;
  }
};

} // namespace math
