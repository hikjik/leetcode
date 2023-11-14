#pragma once

#include <ranges>
#include <string>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::string largestNumber(const std::vector<int> &nums) {
    std::vector<std::string> strs;
    for (auto a : nums) {
      strs.push_back(std::to_string(a));
    }
    std::ranges::sort(strs, [](const std::string &s, const std::string &p) {
      return s + p > p + s;
    });
    std::string ans;
    for (auto s : strs) {
      ans += s;
    }
    return ans.starts_with('0') ? "0" : ans;
  }
};
