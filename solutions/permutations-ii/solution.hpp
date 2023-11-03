#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>> permuteUnique(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<bool> visited(nums.size());
    std::vector<std::vector<int>> permutations;
    std::vector<int> permutation;
    permute(nums, &visited, &permutations, &permutation);
    return permutations;
  }

private:
  static void permute(const std::vector<int> &nums, std::vector<bool> *visited,
                      std::vector<std::vector<int>> *permutations,
                      std::vector<int> *permutation) {
    if (permutation->size() == nums.size()) {
      permutations->push_back(*permutation);
      return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (i && nums[i] == nums[i - 1] && (*visited)[i - 1]) {
        continue;
      }

      if (!(*visited)[i]) {
        (*visited)[i] = true;
        permutation->push_back(nums[i]);
        permute(nums, visited, permutations, permutation);
        permutation->pop_back();
        (*visited)[i] = false;
      }
    }
  }
};
