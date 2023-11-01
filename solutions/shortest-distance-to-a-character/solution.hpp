#pragma once

#include <string>
#include <vector>

/*
  821. Shortest Distance to a Character
  https://leetcode.com/problems/shortest-distance-to-a-character/
  Difficulty: Easy
  Tags: Array, Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> shortestToChar(std::string s, char target) {
    std::vector<int> distances;
    for (auto c : s) {
      distances.push_back(c == target ? 0 : s.size());
    }
    for (int i = 1; i < std::ssize(s); ++i) {
      distances[i] = std::min(distances[i], distances[i - 1] + 1);
    }
    for (int i = s.size() - 2; i >= 0; --i) {
      distances[i] = std::min(distances[i], distances[i + 1] + 1);
    }
    return distances;
  }
};
