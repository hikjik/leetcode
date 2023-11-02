#pragma once

#include <climits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int thirdMax(const std::vector<int> &nums) {
    long long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
    for (auto a : nums) {
      if (a > m1) {
        m3 = m2, m2 = m1, m1 = a;
      } else if (m1 > a && a > m2) {
        m3 = m2, m2 = a;
      } else if (m2 > a && a > m3) {
        m3 = a;
      }
    }
    return m3 == LONG_MIN ? m1 : m3;
  }
};
