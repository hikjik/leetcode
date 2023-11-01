#pragma once

#include <string>
#include <vector>

/*
  2899. Last Visited Integers
  https://leetcode.com/problems/last-visited-integers/
  Difficulty: Easy
  Tags: Array, String, Simulation
  Time:
  Space:
*/

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
