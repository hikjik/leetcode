#pragma once

#include <climits>
#include <queue>
#include <tuple>
#include <vector>

// K = nums.size, M = nums[i].size
// Time: (MKlogK)
// Space: O(K)

class Solution {
public:
  static std::vector<int>
  smallestRange(const std::vector<std::vector<int>> &nums) {
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;

    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < std::ssize(nums); ++i) {
      minHeap.push({nums[i][0], i, 0});
      min = std::min(min, nums[i][0]);
      max = std::max(max, nums[i][0]);
    }

    std::vector<int> ans{min, max};
    while (minHeap.size() == nums.size()) {
      const auto [_, i, j] = minHeap.top();
      minHeap.pop();

      if (j + 1 < std::ssize(nums[i])) {
        minHeap.push({nums[i][j + 1], i, j + 1});
        min = std::get<0>(minHeap.top());
        max = std::max(max, nums[i][j + 1]);
        if (max - min < ans[1] - ans[0]) {
          ans = {min, max};
        }
      }
    }
    return ans;
  }
};
