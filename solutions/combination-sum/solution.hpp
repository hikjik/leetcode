#pragma once

#include <ranges>
#include <span>
#include <vector>

// N is the number of candidates
// T is the target value
// M is the minimal candidate
// Time: O(N^(1+T/M))
// Space: O(T/M)

class Solution {
public:
  static std::vector<std::vector<int>>
  combinationSum(std::vector<int> candidates, int target) {
    std::ranges::sort(candidates);
    std::vector<int> combination;
    std::vector<std::vector<int>> combinations;
    combinationSum(target, std::span{candidates}, &combination, &combinations);
    return combinations;
  }

private:
  static void combinationSum(int target, std::span<int> candidates,
                             std::vector<int> *combination,
                             std::vector<std::vector<int>> *combinations) {
    if (target == 0) {
      combinations->push_back(*combination);
      return;
    }

    for (size_t j = 0; j < candidates.size() && candidates[j] <= target; ++j) {
      combination->push_back(candidates[j]);
      combinationSum(target - candidates[j], candidates.subspan(j), combination,
                     combinations);
      combination->pop_back();
    }
  }
};
