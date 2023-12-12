#pragma once

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int reinitializePermutation(int n) {
    int ans = 0;
    for (int i = 1; !ans || i > 1; i = 2 * i % (n - 1)) {
      ++ans;
    }
    return ans;
  }
};
