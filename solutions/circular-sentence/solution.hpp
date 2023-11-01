#pragma once

#include <string>

/*
  2490. Circular Sentence
  https://leetcode.com/problems/circular-sentence/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool isCircularSentence(std::string sentence) {
    for (size_t i = 0; i < sentence.size(); ++i) {
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
        return false;
      }
    }
    return sentence.front() == sentence.back();
  }
};
