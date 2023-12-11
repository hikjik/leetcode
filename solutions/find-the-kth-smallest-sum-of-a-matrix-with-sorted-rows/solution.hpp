#pragma once

#include <queue>
#include <tuple>
#include <vector>

// Time: O(MKlogK)
// Space: O(K+N)

class Solution {
public:
  static int kthSmallest(const std::vector<std::vector<int>> &mat, int k) {
    auto nums = mat[0];
    for (int i = 1; i < std::ssize(mat); ++i) {
      nums = kSmallestPairs(nums, mat[i], k);
    }
    return nums.back();
  }

private:
  static std::vector<int> kSmallestPairs(const std::vector<int> &nums1,
                                         const std::vector<int> &nums2, int k) {
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, std::greater<>>
        minHeap;
    for (int i = 0; i < k && i < std::ssize(nums1); ++i) {
      minHeap.push({nums1[i] + nums2[0], i, 0});
    }

    std::vector<int> ans;
    while (!minHeap.empty() && k--) {
      const auto [_, i, j] = minHeap.top();
      minHeap.pop();

      ans.push_back(nums1[i] + nums2[j]);

      if (j + 1 < std::ssize(nums2)) {
        minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
      }
    }
    return ans;
  }
};
