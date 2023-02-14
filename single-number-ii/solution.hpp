#pragma once

#include <iostream>
#include <vector>

class Solution {
public:
  static int singleNumber(const std::vector<int> &numbers) {
    int answer = 0;
    for (size_t i = 0; i < 32; ++i) {
      int total = 0;
      for (auto number : numbers) {
        total += (number >> i) & 1;
      }
      if (total % 3 == 1) {
        answer |= (1 << i);
      }
    }
    return answer;
  }
};
