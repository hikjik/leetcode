#pragma once

#include <numeric>
#include <unordered_map>
#include <vector>

// Time: O(NlogM)
// Space: O(M)

class Solution {
public:
  static int subarrayGCD(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> gcds;
    int ans = 0;
    for (auto num : nums) {
      if (num % k == 0) {
        std::unordered_map<int, int> next{{num, 1}};
        for (const auto &[gcd, cnt] : gcds) {
          next[std::gcd(num, gcd)] += cnt;
        }
        ans += next[k];
        gcds.swap(next);
      } else {
        gcds.clear();
      }
    }
    return ans;
  }
};
