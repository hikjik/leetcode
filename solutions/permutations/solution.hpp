#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
    std::vector<int> permutation(nums);
    std::sort(permutation.begin(), permutation.end());

    std::vector<std::vector<int>> permutations;
    do {
      permutations.push_back(permutation);
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    return permutations;
  }
};
