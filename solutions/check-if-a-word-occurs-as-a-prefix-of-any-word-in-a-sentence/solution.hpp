#pragma once

#include <sstream>
#include <string>

/*
  1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
  https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
  Difficulty: Easy
  Tags: String, String Matching
  Time:
  Space:
*/

class Solution {
public:
  static int isPrefixOfWord(std::string sentence, std::string searchWord) {
    std::istringstream stream(sentence);
    int idx = 1;
    for (std::string word; stream >> word;) {
      if (word.starts_with(searchWord)) {
        return idx;
      }
      ++idx;
    }
    return -1;
  }
};
