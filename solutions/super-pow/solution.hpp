#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
private:
  static constexpr int kMod = 1337;

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

public:
  static int superPow(int a, const std::vector<int> &b) {
    a %= kMod;
    int ans = 1;
    for (int i : b) {
      ans = mul(pow(ans, 10), pow(a, i));
    }
    return ans;
  }
};
