#pragma once

#include <string>

class Solution {
public:
  static bool isSumEqual(std::string firstWord, std::string secondWord,
                         std::string targetWord) {
    return value(firstWord) + value(secondWord) == value(targetWord);
  }

private:
  static int value(std::string word) {
    int value = 0;
    for (auto c : word) {
      value = value * 10 + c - 'a';
    }
    return value;
  }
};
