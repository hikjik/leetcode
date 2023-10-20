#pragma once

#include <vector>

class Solution {
public:
  static int singleNumber(const std::vector<int> &numbers) {
    int answer = 0;
    for (auto number : numbers) {
      answer ^= number;
    }
    return answer;
  }
};
