#pragma once

#include <bit>
#include <unordered_map>

// Time: O(logN)
// Space: O(1)

namespace memo {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int integerReplacement(int n) {
    std::unordered_map<int, int> memo{{1, 0}, {INT_MAX, 32}};
    return integerReplacement(n, &memo);
  }

private:
  static int integerReplacement(int n, std::unordered_map<int, int> *memo) {
    if (!memo->contains(n)) {
      if (n & 1) {
        (*memo)[n] = 1 + std::min(integerReplacement(n - 1, memo),
                                  integerReplacement(n + 1, memo));

      } else {
        (*memo)[n] = 1 + integerReplacement(n / 2, memo);
      }
    }
    return (*memo)[n];
  }
};

} // namespace memo

namespace bits {

// Time: O(logN)
// Space: O(1)
class Solution {
public:
  static int integerReplacement(int n) {
    int ans = 0;
    for (unsigned m = n; m > 1; ++ans) {
      if (m & 1) {
        // m = 3 || m = 4k + 1 => --m
        // m = 4k + 3 => ++m
        m != 3 && m & 0b10 ? ++m : --m;
      } else {
        m >>= 1;
      }
    }
    return ans;
  }
};

} // namespace bits
