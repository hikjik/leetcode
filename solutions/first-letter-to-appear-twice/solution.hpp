#pragma once

#include <string>
#include <vector>

/*
  2351. First Letter to Appear Twice
  https://leetcode.com/problems/first-letter-to-appear-twice/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static char repeatedCharacter(std::string s) {
    std::vector<int> counter(128);
    for (auto c : s) {
      if (counter[c]++) {
        return c;
      }
    }
    throw;
  }
};
