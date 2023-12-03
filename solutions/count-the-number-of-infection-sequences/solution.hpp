#pragma once

#include <vector>

// Time: O(NlogN)
// Space: O(N)

// sick = s_0 s_1 ... s_{n-1}
// k_0 s_0 k_1 s_1 ... s_{n-2} k_{n-1} s_{n-1} k_n
// ans = 2^(k_1-1)·...·2^(k_{n-1}-1) · (k_0+k_1+...+k_n)! / (k_0!·k_1!·...·k_n!)

class Solution {
private:
  static constexpr int kMod = 1e9 + 7;

  static int mul(long long a, long long b) { return a * b % kMod; }

  static int pow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1) {
      if (b & 1) {
        res = mul(res, a);
      }
      a = mul(a, a);
    }
    return res;
  }

  static int inv(int a) { return pow(a, kMod - 2); }

public:
  static int numberOfSequence(int n, const std::vector<int> &sick) {
    const int m = n - sick.size();
    std::vector<int> factorials(m + 1);
    factorials[0] = 1;
    for (int i = 1; i <= m; ++i) {
      factorials[i] = mul(factorials[i - 1], i);
    }

    int ans = factorials[m];
    ans = mul(ans, inv(factorials[sick.front()]));
    ans = mul(ans, inv(factorials[n - sick.back() - 1]));
    for (int i = 1; i < std::ssize(sick); ++i) {
      const int k = sick[i] - sick[i - 1] - 1;
      if (k) {
        ans = mul(ans, inv(factorials[k]));
        ans = mul(ans, pow(2, k - 1));
      }
    }
    return ans;
  }
};
