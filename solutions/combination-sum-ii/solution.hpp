#pragma once

#include <ranges>
#include <span>
#include <vector>

// Time: O(N2^N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>>
  combinationSum2(std::vector<int> candidates, int target) {
    std::ranges::sort(candidates);
    std::vector<int> combination;
    std::vector<std::vector<int>> combinations;
    combinationSum2(target, std::span{candidates}, &combination, &combinations);
    return combinations;
  }

private:
  static void combinationSum2(int target, std::span<int> candidates,
                              std::vector<int> *combination,
                              std::vector<std::vector<int>> *combinations) {
    if (target == 0) {
      combinations->push_back(*combination);
      return;
    }
    if (target < 0) {
      return;
    }

    for (size_t j = 0; j < candidates.size(); ++j) {
      if (j && candidates[j] == candidates[j - 1]) {
        continue;
      }
      combination->push_back(candidates[j]);
      combinationSum2(target - candidates[j], candidates.subspan(j + 1),
                      combination, combinations);
      combination->pop_back();
    }
  }
};
