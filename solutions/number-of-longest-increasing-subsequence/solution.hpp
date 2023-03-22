#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int findNumberOfLIS(const std::vector<int> &nums) {
    std::vector<int> length(nums.size(), 1);
    std::vector<int> cnt(nums.size(), 1);
    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          if (length[i] < 1 + length[j]) {
            length[i] = 1 + length[j];
            cnt[i] = cnt[j];
          } else if (length[i] == 1 + length[j]) {
            cnt[i] += cnt[j];
          }
        }
      }
    }

    const auto max_length = *std::max_element(length.begin(), length.end());
    int max_cnt = 0;
    for (size_t i = 0; i < length.size(); ++i) {
      if (length[i] == max_length) {
        max_cnt += cnt[i];
      }
    }
    return max_cnt;
  }
};
