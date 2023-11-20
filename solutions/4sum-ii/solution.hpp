#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
  static int fourSumCount(const std::vector<int> &nums1,
                          const std::vector<int> &nums2,
                          const std::vector<int> &nums3,
                          const std::vector<int> &nums4) {
    std::unordered_map<int, int> map;
    for (auto a : nums1) {
      for (auto b : nums2) {
        ++map[a + b];
      }
    }

    int ans = 0;
    for (auto a : nums3) {
      for (auto b : nums4) {
        if (auto it = map.find(-a - b); it != map.end()) {
          ans += it->second;
        }
      }
    }
    return ans;
  }
};
