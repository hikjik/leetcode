#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN + logT), T = target, N = |coins|
// Space: O(N)

class Solution {
public:
  static int minimumAddedCoins(std::vector<int> coins, int target) {
    std::ranges::sort(coins);
    int ans = 0;
    for (int j = 0, sum = 1; sum <= target;) {
      if (j == ssize(coins) || coins[j] > sum) {
        ++ans;
        sum += sum;
      } else {
        sum += coins[j++];
      }
    }
    return ans;
  }
};
