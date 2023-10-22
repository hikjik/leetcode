#pragma once

#include <vector>

class Solution {
public:
  static int maximumScore(const std::vector<int> &nums, int k) {
    const int n = nums.size();
    int max_score = nums[k];
    for (int l = k, r = k, min = nums[k]; l > 0 || r < n - 1;) {
      if (l == 0 || r < n - 1 && nums[l - 1] < nums[r + 1]) {
        min = std::min(min, nums[++r]);
      } else {
        min = std::min(min, nums[--l]);
      }
      max_score = std::max(max_score, min * (r - l + 1));
    }
    return max_score;
  }
};
