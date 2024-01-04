#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> anagramMappings(const std::vector<int> &nums1,
                                          const std::vector<int> &nums2) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < std::ssize(nums2); ++i) {
      map[nums2[i]] = i;
    }
    std::vector<int> ans;
    for (auto num : nums1) {
      ans.push_back(map[num]);
    }
    return ans;
  }
};
