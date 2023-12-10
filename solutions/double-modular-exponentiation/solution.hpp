#pragma once

#include <vector>

// Time: O(NlogM)
// Space: O(1)

class Solution {
public:
  static std::vector<int>
  getGoodIndices(const std::vector<std::vector<int>> &variables, int target) {
    std::vector<int> ans;
    for (int i = 0; i < std::ssize(variables); ++i) {
      const auto &p = variables[i];
      const auto a = p[0], b = p[1], c = p[2], m = p[3];
      if (pow(pow(a, b, 10), c, m) == target) {
        ans.push_back(i);
      }
    }
    return ans;
  }

private:
  static int mul(long long a, long long b, int mod) { return a * b % mod; }

  static int pow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
      if (b & 1) {
        res = mul(res, a, mod);
      }
      a = mul(a, a, mod);
    }
    return res;
  }
};
