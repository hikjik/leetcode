#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (map.contains(nums[i])) {
        return {map[nums[i]], i};
      }
      map[target - nums[i]] = i;
    }
    return {};
  }
};
