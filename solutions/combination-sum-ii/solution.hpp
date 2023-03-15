#pragma once

#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  combinationSum2(std::vector<int> candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    std::vector<std::vector<int>> combinations;
    std::vector<int> combination;
    combinationSum2(0, candidates, target, &combinations, &combination);
    return combinations;
  }

private:
  static void combinationSum2(size_t i, const std::vector<int> &candidates,
                              int target,
                              std::vector<std::vector<int>> *combinations,
                              std::vector<int> *combination) {
    if (target == 0) {
      combinations->push_back(*combination);
      return;
    }

    for (size_t j = i; j < candidates.size(); ++j) {
      if (j > i && candidates[j] == candidates[j - 1]) {
        continue;
      }

      if (candidates[i] > target) {
        break;
      }

      combination->push_back(candidates[j]);
      combinationSum2(j + 1, candidates, target - candidates[j], combinations,
                      combination);
      combination->pop_back();
    }
  }
};
