#pragma once

#include <string>
#include <unordered_set>

class Solution {
public:
  static int countVowelSubstrings(std::string word) {
    static const std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    int cnt = 0;
    for (size_t i = 0; i < word.size(); ++i) {
      std::unordered_set<char> letters;
      for (size_t j = i; j < word.size(); ++j) {
        if (!vowels.contains(word[j])) {
          break;
        }
        letters.insert(word[j]);
        if (letters.size() == vowels.size()) {
          ++cnt;
        }
      }
    }
    return cnt;
  }
};
