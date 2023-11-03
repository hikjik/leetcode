#pragma once

#include <cstdint>

// Time:
// Space:

class Solution {
public:
  static int hammingWeight(std::uint32_t n) { return __builtin_popcount(n); }
};
