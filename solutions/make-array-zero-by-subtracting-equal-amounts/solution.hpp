#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  static int minimumOperations(const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    set.erase(0);
    return set.size();
  }
};
