#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> table;
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
      if (auto it = table.find(nums[i]); it != table.end()) {
        return {i, it->second};
      }
      table[target - nums[i]] = i;
    }

    return {};
  }
};
