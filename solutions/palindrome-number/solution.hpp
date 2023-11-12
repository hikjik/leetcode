#pragma once

#include <algorithm>
#include <climits>
#include <string>

// Time: O(logN)
// Space: O(1)

namespace stl {

// Time: O(logN)
// Space: O(logN)
class Solution {
public:
  static bool isPalindrome(int n) {
    const auto str = std::to_string(n);
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2,
                      str.crbegin());
  }
};

} // namespace stl

namespace reverse {

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static bool isPalindrome(int n) { return n >= 0 && n == reverse(n); }

private:
  // [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)
  static int reverse(int n) {
    int ans = 0;
    for (int i = n; i; i /= 10) {
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
        return 0;
      }
      ans = ans * 10 + i % 10;
    }
    return ans;
  }
};

} // namespace reverse
