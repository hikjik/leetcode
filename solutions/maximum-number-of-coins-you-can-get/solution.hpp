#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

namespace stl_sort {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int maxCoins(std::vector<int> piles) {
    std::ranges::sort(piles);

    int ans = 0;
    for (int i = piles.size() / 3; i < std::ssize(piles); i += 2) {
      ans += piles[i];
    }
    return ans;
  }
};

} // namespace stl_sort

namespace counting_sort {

// Time: O(M), where M is the max element in nums
// Space: O(N)
class Solution {
public:
  static int maxCoins(std::vector<int> piles) {
    std::vector<int> counter(std::ranges::max(piles) + 1);
    for (auto a : piles) {
      ++counter[a];
    }
    for (int i = 0, j = 0; i < std::ssize(counter); ++i) {
      while (counter[i]--) {
        piles[j++] = i;
      }
    }

    int ans = 0;
    for (int i = piles.size() / 3; i < std::ssize(piles); i += 2) {
      ans += piles[i];
    }
    return ans;
  }
};

} // namespace counting_sort
