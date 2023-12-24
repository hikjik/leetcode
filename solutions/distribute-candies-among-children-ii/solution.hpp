#pragma once

#include <algorithm>

// Time: O(1)
// Space: O(1)

namespace linear {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static long long distributeCandies(int n, int l) {
    long long ans = 0;
    for (int i = std::max(0, n - 2 * l); i <= std::min(n, l); ++i) {
      ans += std::min(n - i, l) - std::max(0, n - i - l) + 1;
    }
    return ans;
  }
};

} // namespace linear

namespace combinatorics {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  static long long distributeCandies(int n, int l) {
    return c2(n + 2) - 3 * c2(n - l + 1) + 3 * c2(n - 2 * l) -
           c2(n - 3 * l - 1);
  }

  static long long c2(long long n) { return n < 2 ? 0 : n * (n - 1) / 2; }
};

} // namespace combinatorics
