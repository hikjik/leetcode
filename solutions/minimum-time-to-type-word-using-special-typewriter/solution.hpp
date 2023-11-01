#pragma once

#include <string>

/*
  1974. Minimum Time to Type Word Using Special Typewriter
  https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
  Difficulty: Easy
  Tags: String, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int minTimeToType(std::string word) {
    int ans = 0;
    for (char a = 'a'; auto b : word) {
      ans += std::min(std::abs(a - b), 26 - std::abs(a - b)) + 1;
      a = b;
    }
    return ans;
  }
};
