#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  949. Largest Time for Given Digits
  https://leetcode.com/problems/largest-time-for-given-digits/
  Difficulty: Medium
  Tags: String, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static std::string largestTimeFromDigits(std::vector<int> arr) {
    std::string max_time;
    std::sort(arr.begin(), arr.end());
    do {
      const auto h = std::to_string(arr[0]) + std::to_string(arr[1]);
      const auto m = std::to_string(arr[2]) + std::to_string(arr[3]);
      if (h < "24" && m < "60") {
        max_time = std::max(max_time, h + ":" + m);
      }
    } while (std::next_permutation(arr.begin(), arr.end()));
    return max_time;
  }
};
