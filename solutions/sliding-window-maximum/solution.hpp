#pragma once

#include <queue>
#include <vector>

class Solution {
public:
  static std::vector<int> maxSlidingWindow(const std::vector<int> &nums,
                                           int k) {
    const int n = nums.size();
    std::deque<int> deque;
    std::vector<int> maximums(n - k + 1);
    for (int i = 0; i < n; ++i) {
      while (!deque.empty() && deque.back() < nums[i]) {
        deque.pop_back();
      }
      deque.push_back(nums[i]);
      if (i >= k && nums[i - k] == deque.front()) {
        deque.pop_front();
      }
      if (i >= k - 1) {
        maximums[i - k + 1] = deque.front();
      }
    }
    return maximums;
  }
};
