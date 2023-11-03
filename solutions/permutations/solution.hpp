#pragma once

#include <ranges>
#include <vector>

// Time: O(N!)
// Space: O(N)

namespace backtracking {

// Time: O(N!)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
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

} // namespace backtracking

namespace stl {

// Time: O(N!)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>> permute(std::vector<int> nums) {
    std::ranges::sort(nums);
    std::vector<std::vector<int>> permutations;
    do {
      permutations.push_back(nums);
    } while (std::ranges::next_permutation(nums).found);
    return permutations;
  }
};

} // namespace stl
