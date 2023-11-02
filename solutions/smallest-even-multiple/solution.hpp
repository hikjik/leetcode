#pragma once

#include <numeric>

// Time:
// Space:

class Solution {
public:
  static int smallestEvenMultiple(int n) { return std::lcm(n, 2); }
};
