#pragma once

#include <sstream>
#include <string>

// Time:
// Space:

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
