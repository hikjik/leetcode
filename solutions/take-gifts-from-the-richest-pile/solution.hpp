#pragma once

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

/*
  2558. Take Gifts From the Richest Pile
  https://leetcode.com/problems/take-gifts-from-the-richest-pile/
  Difficulty: Easy
  Tags: Array, Heap (Priority Queue), Simulation
  Time:
  Space:
*/

class Solution {
public:
  static long long pickGifts(std::vector<int> gifts, int k) {
    std::make_heap(gifts.begin(), gifts.end());
    while (k--) {
      std::pop_heap(gifts.begin(), gifts.end());
      gifts.back() = std::sqrt(gifts.back());
      std::push_heap(gifts.begin(), gifts.end());
    }
    return std::accumulate(gifts.begin(), gifts.end(), 0LL);
  }
};
