#pragma once

#include <queue>
#include <tuple>
#include <vector>

// Time: O(KlogK)
// Space: O(K)

class Solution {
public:
  static std::vector<std::vector<int>>
  kSmallestPairs(const std::vector<int> &nums1, const std::vector<int> &nums2,
                 int k) {
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;
    for (int i = 0; i < k && i < std::ssize(nums1); ++i) {
      minHeap.push({nums1[i] + nums2[0], i, 0});
    }

    std::vector<std::vector<int>> ans;
    while (!minHeap.empty() && k--) {
      const auto [_, i, j] = minHeap.top();
      minHeap.pop();

      ans.push_back({nums1[i], nums2[j]});

      if (j + 1 < std::ssize(nums2)) {
        minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
      }
    }
    return ans;
  }
};
