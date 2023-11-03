#pragma once

#include <algorithm>
#include <span>
#include <vector>

// Time: O(N2^N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>> subsetsWithDup(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> subset;
    std::vector<std::vector<int>> subsets;
    enumerateSubsets(std::span{nums}, &subset, &subsets);
    return subsets;
  }

private:
  static void enumerateSubsets(std::span<int> nums, std::vector<int> *subset,
                               std::vector<std::vector<int>> *subsets) {
    subsets->push_back(*subset);
    for (int j = 0; j < std::ssize(nums); ++j) {
      if (j && nums[j - 1] == nums[j]) {
        continue;
      }
      subset->push_back(nums[j]);
      enumerateSubsets(nums.subspan(j + 1), subset, subsets);
      subset->pop_back();
    }
  }
};
