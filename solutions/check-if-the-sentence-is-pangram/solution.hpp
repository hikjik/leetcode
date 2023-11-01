#pragma once

#include <string>
#include <unordered_set>

/*
  1832. Check if the Sentence Is Pangram
  https://leetcode.com/problems/check-if-the-sentence-is-pangram/
  Difficulty: Easy
  Tags: Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static bool checkIfPangram(std::string sentence) {
    return std::unordered_set(sentence.begin(), sentence.end()).size() == 26;
  }
};
