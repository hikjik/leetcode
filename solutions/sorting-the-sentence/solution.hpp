#pragma once

#include <sstream>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::string sortSentence(std::string s) {
    std::vector<std::string> words(10);
    std::istringstream stream(s);
    for (std::string word; stream >> word;) {
      words[word.back() - '0'] = word.substr(0, word.size() - 1);
    }

    std::string sentence;
    for (const auto &word : words) {
      if (!word.empty() && !sentence.empty()) {
        sentence += " ";
      }
      sentence += word;
    }
    return sentence;
  }
};
