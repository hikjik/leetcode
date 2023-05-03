#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  findDifference(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::vector<std::unordered_set<int>> sets{
        {nums1.begin(), nums1.end()},
        {nums2.begin(), nums2.end()},
    };

    std::vector<std::vector<int>> ans(2);
    for (size_t i = 0; i < 2; ++i) {
      for (auto s : sets[i]) {
        if (!sets[1 - i].count(s)) {
          ans[i].push_back(s);
        }
      }
    }
    return ans;
  }
};
