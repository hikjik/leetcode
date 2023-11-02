#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<int>
  lastVisitedIntegers(const std::vector<std::string> &words) {
    std::vector<int> last_visited;
    std::vector<int> nums;
    size_t j = 0;
    for (const auto &word : words) {
      if (word == "prev") {
        last_visited.push_back(j ? nums[--j] : -1);
      } else {
        nums.push_back(std::stoi(word));
        j = nums.size();
      }
    }
    return last_visited;
  }
};
