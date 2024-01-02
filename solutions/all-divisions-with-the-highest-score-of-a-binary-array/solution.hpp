#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> maxScoreIndices(const std::vector<int> &nums) {
    int maxScore = std::ranges::count(nums, 1);
    std::vector<int> ans{0};
    for (int score = maxScore, i = 0; i < std::ssize(nums); ++i) {
      score += 1 - 2 * nums[i];
      if (score > maxScore) {
        maxScore = score;
        ans = {i + 1};
      } else if (score == maxScore) {
        ans.push_back(i + 1);
      }
    }
    return ans;
  }
};
