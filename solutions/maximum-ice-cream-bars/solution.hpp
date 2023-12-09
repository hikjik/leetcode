#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxIceCream(const std::vector<int> &costs, int coins) {
    std::vector<int> counter(std::ranges::max(costs) + 1);
    for (auto c : costs) {
      ++counter[c];
    }

    int ans = 0;
    for (int price = 1; price < std::ssize(counter); ++price) {
      if (counter[price]) {
        const int amount = std::min(coins / price, counter[price]);
        ans += amount;
        coins -= amount * price;
      }
    }
    return ans;
  }
};
