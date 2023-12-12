#pragma once

#include <cmath>

// Time: O(1)
// Space: O(1)

namespace binary_search {

// Time: O(logN)
// Space: O(1)
class Solution {
public:
  static int twoEggDrop(int n) {
    int left = 1, right = n;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      middle *(middle + 1) / 2 >= n ? right = middle : left = middle + 1;
    }
    return left;
  }
};

} // namespace binary_search

namespace math {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  static int twoEggDrop(int n) {
    return std::ceil((-1.0 + std::sqrt(1 + 8 * n)) / 2.0);
  }
};

} // namespace math
