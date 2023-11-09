#pragma once

#include <bit>
#include <cstdint>

// Time: O(1)
// Space: O(1)

namespace naive {

// Time: O(logN)
// Space: O(1)
class Solution {
public:
  static int hammingWeight(uint32_t n) {
    int ans = 0;
    for (auto i = n; i; i >>= 1) {
      ans += i & 1;
    }
    return ans;
  }
};

} // namespace naive

namespace builtin {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  static int hammingWeight(uint32_t n) { return std::popcount(n); }
};

} // namespace builtin
