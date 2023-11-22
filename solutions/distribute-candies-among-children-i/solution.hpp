#pragma once

// Time: O(L^2), where L = limit
// Space: O(1)

class Solution {
public:
  static int distributeCandies(int n, int limit) {
    int ans = 0;
    for (int i = 0; i <= limit; ++i) {
      for (int j = 0; j <= limit; ++j) {
        const auto k = n - i - j;
        ans += k >= 0 && k <= limit;
      }
    }
    return ans;
  }
};
