#pragma once

#include <vector>

class Solution {
public:
  static int majorityElement(const std::vector<int> &nums) {
    int cnt = 0, majority = 0;
    for (auto num : nums) {
      if (!cnt) {
        majority = num;
      }
      cnt += majority == num ? 1 : -1;
    }
    return majority;
  }
};
