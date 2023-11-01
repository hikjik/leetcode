#pragma once

#include <set>
#include <string>

/*
  1796. Second Largest Digit in a String
  https://leetcode.com/problems/second-largest-digit-in-a-string/
  Difficulty: Easy
  Tags: Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static int secondHighest(std::string s) {
    std::set<char, std::greater<>> set;
    for (auto c : s) {
      if (std::isdigit(c)) {
        set.insert(c - '0');
      }
    }
    return set.size() > 1 ? *std::next(set.begin()) : -1;
  }
};
