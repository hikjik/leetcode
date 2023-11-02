#pragma once

#include <algorithm>

// Time:
// Space:

class Solution {
public:
  static int distMoney(int money, int children) {
    if (money < children) {
      return -1;
    }

    const auto q = (money - children) / 7;
    const auto r = (money - children) % 7;

    if (q == children && r == 0) {
      return q;
    }
    if (q == children - 1 && r == 3) {
      return q - 1;
    }
    return std::min(q, children - 1);
  }
};
