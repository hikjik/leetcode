#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  mergeArrays(const std::vector<std::vector<int>> &nums1,
              const std::vector<std::vector<int>> &nums2) {
    std::vector<std::vector<int>> ans;
    for (auto it1 = nums1.begin(), it2 = nums2.begin();
         it1 != nums1.end() || it2 != nums2.end();) {
      if (it1 == nums1.end()) {
        ans.push_back(*it2++);
      } else if (it2 == nums2.end()) {
        ans.push_back(*it1++);
      } else if (it1->front() < it2->front()) {
        ans.push_back(*it1++);
      } else if (it2->front() < it1->front()) {
        ans.push_back(*it2++);
      } else {
        ans.push_back({it1->front(), it1->back() + it2->back()});
        ++it1, ++it2;
      }
    }
    return ans;
  }
};
