#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
  static int countKDifference(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    int cnt = 0;
    for (auto a : nums) {
      cnt += map[a - k] + map[a + k];
      ++map[a];
    }
    return cnt;
  }
};
