#pragma once

#include <cstdint>

/*
  190. Reverse Bits
  https://leetcode.com/problems/reverse-bits/
  Difficulty: Easy
  Tags: Divide and Conquer, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::uint32_t reverseBits(std::uint32_t n) {
    std::uint32_t reversed = 0;
    for (int l = 31; n; --l, n >>= 1) {
      reversed += (n & 1) << l;
    }
    return reversed;
  }
};
