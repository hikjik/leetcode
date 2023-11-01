#pragma once

#include <string>
#include <vector>

/*
  2515. Shortest Distance to Target String in a Circular Array
  https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int closetTarget(const std::vector<std::string> &words,
                          std::string target, int start) {
    const int n = words.size();
    for (int i = 0; i < n; ++i) {
      if (words[(start + i) % n] == target ||
          words[(start - i + n) % n] == target) {
        return i;
      }
    }
    return -1;
  }
};
