#pragma once

#include <sstream>
#include <string>

/*
  2042. Check if Numbers Are Ascending in a Sentence
  https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool areNumbersAscending(std::string s) {
    std::istringstream stream(s);
    int prev = 0;
    for (std::string token; stream >> token;) {
      if (std::isdigit(token[0])) {
        const auto number = std::stoi(token);
        if (prev >= number) {
          return false;
        }
        prev = number;
      }
    }
    return true;
  }
};
