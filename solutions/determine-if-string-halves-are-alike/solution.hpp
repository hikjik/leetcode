#pragma once

#include <string>
#include <unordered_set>

class Solution {
public:
  static bool halvesAreAlike(std::string s) {
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (isVowel(s[i])) {
        cnt += i < s.size() / 2 ? 1 : -1;
      }
    }
    return cnt == 0;
  }

private:
  static bool isVowel(char c) {
    static const std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                                 'A', 'E', 'I', 'O', 'U'};
    return vowels.contains(c);
  }
};
