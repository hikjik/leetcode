#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)
// Notes: [Catalan Number](https://w.wiki/845b)

namespace naive {

// Time: O(Cat(N))
// Space: O(N)
class Solution {
public:
  static int numTrees(int n) {
    if (n <= 1) {
      return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += numTrees(i) * numTrees(n - i - 1);
    }
    return ans;
  }
};

} // namespace naive

namespace dp {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }

    return dp[n];
  }
};

} // namespace dp

namespace combinatorics {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int numTrees(int n) {
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      ans = ans * 2LL * (2 * i + 1) / (i + 2);
    }
    return ans;
  }
};

} // namespace combinatorics
