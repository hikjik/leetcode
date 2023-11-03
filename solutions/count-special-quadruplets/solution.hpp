#pragma once

#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int countQuadruplets(const std::vector<int> &nums) {
    std::unordered_map<int, int> map;
    int cnt = 0;
    for (int b = 1; b < std::ssize(nums); ++b) {
      for (int a = 0; a < b; ++a) {
        ++map[nums[a] + nums[b]];
      }
      for (int c = b + 1, d = c + 1; d < std::ssize(nums); ++d) {
        cnt += map[nums[d] - nums[c]];
      }
    }
    return cnt;
  }
};
