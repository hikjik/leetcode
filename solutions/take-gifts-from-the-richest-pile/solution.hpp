#pragma once

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

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
