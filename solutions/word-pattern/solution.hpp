#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool wordPattern(std::string pattern, std::string s) {
    int n = pattern.size();
    std::stringstream stream(s);
    std::unordered_map<std::string, int> words;
    std::vector<int> letters(128);

    int i = 0;
    std::string word;
    while (i < n && !stream.eof()) {
      stream >> word;
      auto letter = pattern[i];
      if (words[word] != letters[letter]) {
        return false;
      }
      words[word] = letters[letter] = ++i;
    }
    return i == n && stream.eof();
  }
};
