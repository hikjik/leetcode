#pragma once

// Time: O(1)
// Space: O(1)

namespace linear {

// Time: O(N)
// Space: O(1)
// f(1) = 0, f(2) = 1, f(n) = n-1 + f(n-2)
class Solution {
public:
  static int minOperations(int n) {
    int ans = 0;
    for (; n > 1; n -= 2) {
      ans += n - 1;
    }
    return ans;
  }
};

} // namespace linear

namespace constant {

// Time: O(1)
// Space: O(1)
class Solution {
public:
  static int minOperations(int n) {
    return (n - 1 + (n & 1 ? 3 : 2)) / 2 * (n / 2);
  }
};

} // namespace constant
