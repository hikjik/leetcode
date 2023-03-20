#pragma once

#include <vector>

class Solution {
public:
  static bool canPlaceFlowers(std::vector<int> flowerbed, int n) {
    for (size_t i = 0; i < flowerbed.size(); ++i) {
      if (!flowerbed[i] && (i == 0 || !flowerbed[i - 1]) &&
          (i == flowerbed.size() - 1 || !flowerbed[i + 1])) {
        flowerbed[i] = 1;
        --n;
      }
    }
    return n <= 0;
  }
};