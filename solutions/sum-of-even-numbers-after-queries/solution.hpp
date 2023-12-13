#pragma once

#include <vector>

// Time: O(N+Q)
// Space: O(N)

class Solution {
public:
  static std::vector<int>
  sumEvenAfterQueries(std::vector<int> nums,
                      const std::vector<std::vector<int>> &queries) {
    int evenSum = 0;
    for (auto num : nums) {
      evenSum += num & 1 ? 0 : num;
    }

    std::vector<int> ans;
    for (const auto &query : queries) {
      const auto idx = query[1], val = query[0];
      evenSum -= nums[idx] & 1 ? 0 : nums[idx];
      nums[idx] += val;
      evenSum += nums[idx] & 1 ? 0 : nums[idx];
      ans.push_back(evenSum);
    }
    return ans;
  }
};
