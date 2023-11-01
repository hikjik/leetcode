#pragma once

#include <algorithm>
#include <vector>

/*
  2706. Buy Two Chocolates
  https://leetcode.com/problems/buy-two-chocolates/
  Difficulty: Easy
  Tags: Array, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int buyChoco(std::vector<int> prices, int money) {
    std::partial_sort(prices.begin(), prices.begin() + 2, prices.end());
    const auto cost = prices[0] + prices[1];
    return cost > money ? money : money - cost;
  }
};
