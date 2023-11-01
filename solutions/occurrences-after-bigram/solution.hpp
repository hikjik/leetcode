#pragma once

#include <sstream>
#include <string>
#include <vector>

/*
  1078. Occurrences After Bigram
  https://leetcode.com/problems/occurrences-after-bigram/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  findOcurrences(std::string text, std::string first, std::string second) {
    std::stringstream stream(text);
    std::vector<std::string> words;
    for (std::string p1, p2, word; stream >> word; p1 = p2, p2 = word) {
      if (p1 == first && p2 == second) {
        words.push_back(word);
      }
    }
    return words;
  }
};
