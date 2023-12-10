#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

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
  static int numberOfGoodPartitions(const std::vector<int> &nums) {
    const int n = nums.size();

    std::unordered_map<int, int> last;
    for (int i = 0; i < n; ++i) {
      last[nums[i]] = i;
    }

    int cnt = 0;
    for (int l = 0, r = 0; l < n; ++l) {
      r = std::max(r, last[nums[l]]);
      cnt += l == r;
    }
    return pow(2, cnt - 1);
  }
};
