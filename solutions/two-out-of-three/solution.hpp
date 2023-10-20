#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  static std::vector<int> twoOutOfThree(const std::vector<int> &nums1,
                                        const std::vector<int> &nums2,
                                        const std::vector<int> &nums3) {
    std::unordered_map<int, int> counter;
    for (const auto &nums : {nums1, nums2, nums3}) {
      for (auto a : std::unordered_set(nums.begin(), nums.end())) {
        ++counter[a];
      }
    }

    std::vector<int> ans;
    for (const auto &[a, f] : counter) {
      if (f > 1) {
        ans.push_back(a);
      }
    }
    return ans;
  }
};
