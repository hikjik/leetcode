#pragma once

#include <cstdint>

class Solution {
public:
  static int hammingWeight(std::uint32_t n) { return __builtin_popcount(n); }
};
