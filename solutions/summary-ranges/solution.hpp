#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::vector<std::string> summaryRanges(const std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<std::string> ranges;
    for (int begin = 0; begin < n;) {
      int end = begin + 1;
      while (end < n && nums[end - 1] + 1 == nums[end]) {
        ++end;
      }
      if (begin + 1 == end) {
        ranges.push_back(std::to_string(nums[begin]));
      } else {
        ranges.push_back(std::to_string(nums[begin]) + "->" +
                         std::to_string(nums[end - 1]));
      }
      begin = end;
    }
    return ranges;
  }
};
