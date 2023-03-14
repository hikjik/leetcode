#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  combinationSum(const std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> combinations;
    std::vector<int> combination;
    combinationSum(0, candidates, target, &combinations, &combination);
    return combinations;
  }

private:
  static void combinationSum(size_t i, const std::vector<int> &candidates,
                             int target,
                             std::vector<std::vector<int>> *combinations,
                             std::vector<int> *combination) {
    if (target < 0 || i == candidates.size()) {
      return;
    }
    if (target == 0) {
      combinations->push_back(*combination);
      return;
    }

    combination->push_back(candidates[i]);
    combinationSum(i, candidates, target - candidates[i], combinations,
                   combination);
    combination->pop_back();
    combinationSum(i + 1, candidates, target, combinations, combination);
  }
};
