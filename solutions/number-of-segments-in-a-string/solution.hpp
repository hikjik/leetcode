#pragma once

#include <sstream>
#include <string>

/*
  434. Number of Segments in a String
  https://leetcode.com/problems/number-of-segments-in-a-string/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int countSegments(std::string s) {
    std::stringstream sstream(s);
    int count = 0;
    for (std::string a; sstream >> a;) {
      ++count;
    }
    return count;
  }
};
