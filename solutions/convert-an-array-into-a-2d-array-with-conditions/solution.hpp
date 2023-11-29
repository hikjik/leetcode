#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::vector<int>>
  findMatrix(const std::vector<int> &nums) {
    std::vector<int> counter(nums.size() + 1);
    std::vector<std::vector<int>> ans;
    for (auto a : nums) {
      if (counter[a] >= std::ssize(ans)) {
        ans.emplace_back();
      }
      ans[counter[a]++].push_back(a);
    }
    return ans;
  }
};
