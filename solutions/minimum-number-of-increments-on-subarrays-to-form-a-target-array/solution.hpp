#pragma once

#include <vector>

class Solution {
public:
  static int minNumberOperations(const std::vector<int> &target) {
    int cnt = target.front();
    for (size_t i = 1; i < target.size(); ++i) {
      if (target[i - 1] < target[i]) {
        cnt += target[i] - target[i - 1];
      }
    }
    return cnt;
  }
};