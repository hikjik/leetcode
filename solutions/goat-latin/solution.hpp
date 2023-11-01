#pragma once

#include <sstream>
#include <string>

/*
  824. Goat Latin
  https://leetcode.com/problems/goat-latin/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string toGoatLatin(std::string sentence) {
    std::string ans;
    std::istringstream stream(sentence);
    for (std::string word, suffix = "a"; stream >> word; suffix += "a") {
      if (!isVowel(word.front())) {
        std::rotate(word.begin(), word.begin() + 1, word.end());
      }
      ans += (ans.empty() ? "" : " ") + word + "ma" + suffix;
    }
    return ans;
  }

private:
  static bool isVowel(char c) {
    c = std::tolower(c);
    return c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'u';
  }
};
