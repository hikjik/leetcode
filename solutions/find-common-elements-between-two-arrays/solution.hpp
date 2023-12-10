#pragma once

#include <unordered_set>
#include <vector>

// Time: O(N+M)
// Space: O(N+M)

class Solution {
public:
  static std::vector<int>
  findIntersectionValues(const std::vector<int> &nums1,
                         const std::vector<int> &nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    std::vector<int> ans(2);
    for (auto a : nums1) {
      ans[0] += set2.contains(a);
    }
    for (auto a : nums2) {
      ans[1] += set1.contains(a);
    }
    return ans;
  }
};
