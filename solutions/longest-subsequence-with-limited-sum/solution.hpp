#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  static std::vector<int> answerQueries(std::vector<int> nums,
                                        const std::vector<int> &queries) {
    std::sort(nums.begin(), nums.end());
    std::partial_sum(nums.cbegin(), nums.cend(), nums.begin());
    std::vector<int> ans;
    for (auto query : queries) {
      ans.push_back(std::upper_bound(nums.cbegin(), nums.cend(), query) -
                    nums.cbegin());
    }
    return ans;
  }
};
