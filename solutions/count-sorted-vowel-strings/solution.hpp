#pragma once

#include <array>
#include <numeric>

// Time: O(1)
// Space: O(1)

namespace dp {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int countVowelStrings(int n) {
    std::array<int, 5> dp{1, 1, 1, 1, 1};
    while (--n) {
      std::partial_sum(dp.rbegin(), dp.rend(), dp.rbegin());
    }
    return std::reduce(dp.begin(), dp.end());
  }
};

} // namespace dp

namespace combinatorics {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  // C(n + 4, 4)
  static int countVowelStrings(int n) {
    return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
  }
};

} // namespace combinatorics
