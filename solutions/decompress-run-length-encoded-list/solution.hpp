#pragma once

#include <vector>

class Solution {
public:
  static std::vector<int> decompressRLElist(const std::vector<int> &nums) {
    std::vector<int> ans;
    for (size_t i = 0; i < nums.size(); i += 2) {
      ans.insert(ans.end(), nums[i], nums[i + 1]);
    }
    return ans;
  }
};
