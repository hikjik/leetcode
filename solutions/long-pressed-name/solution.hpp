#pragma once

#include <string>

/*
  925. Long Pressed Name
  https://leetcode.com/problems/long-pressed-name/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static bool isLongPressedName(std::string name, std::string typed) {
    size_t i = 0;
    for (auto c : typed) {
      if (i < name.size() && name[i] == c) {
        i++;
      } else if (i == 0 || name[i - 1] != c) {
        return false;
      }
    }
    return i == name.size();
  }
};
