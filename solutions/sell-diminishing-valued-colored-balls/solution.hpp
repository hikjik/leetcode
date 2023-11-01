#pragma once

#include <algorithm>
#include <vector>

/*
  1648. Sell Diminishing-Valued Colored Balls
  https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
  Difficulty: Medium
  Tags: Array, Math, Binary Search, Greedy, Sorting, Heap (Priority Queue)
  Time:
  Space:
*/

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int maxProfit(std::vector<int> inventory, int orders) {
    int left = 0, right = *std::max_element(inventory.begin(), inventory.end());
    while (left < right) {
      const auto middle = left + (right - left) / 2;

      long long total = 0;
      for (auto frequency : inventory) {
        total += std::max(frequency - middle, 0);
      }
      total > orders ? left = middle + 1 : right = middle;
    }

    long long profit = 0;
    for (auto frequency : inventory) {
      if (frequency > left) {
        profit += (frequency + left + 1LL) * (frequency - left) / 2;
        orders -= frequency - left;
      }
    }
    profit += 1LL * left * orders;
    return profit % kMod;
  }
};
