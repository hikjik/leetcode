#pragma once

#include <vector>

class Solution {
public:
  static long long zeroFilledSubarray(const std::vector<int> &nums) {
    long long res = 0, cnt = 0;
    for (auto num : nums) {
      if (!num) {
        cnt++;
      } else {
        res += (cnt + 1) * cnt / 2;
        cnt = 0;
      }
    }
    return res + (cnt + 1) * cnt / 2;
  }
};
