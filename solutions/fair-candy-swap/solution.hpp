#pragma once

#include <numeric>
#include <unordered_set>
#include <vector>

/*
  888. Fair Candy Swap
  https://leetcode.com/problems/fair-candy-swap/
  Difficulty: Easy
  Tags: Array, Hash Table, Binary Search, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> fairCandySwap(const std::vector<int> &alice,
                                        const std::vector<int> &bob) {
    const auto alice_total = std::accumulate(alice.begin(), alice.end(), 0);
    const auto bob_total = std::accumulate(bob.begin(), bob.end(), 0);
    const auto delta = (alice_total - bob_total) / 2;

    std::unordered_set set(alice.begin(), alice.end());
    for (auto b : bob) {
      if (set.contains(b + delta)) {
        return {b + delta, b};
      }
    }
    throw;
  }
};
