#pragma once

#include <numeric>

class Solution {
public:
  static int smallestEvenMultiple(int n) { return std::lcm(n, 2); }
};
