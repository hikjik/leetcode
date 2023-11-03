#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string> uncommonFromSentences(std::string s1,
                                                        std::string s2) {
    std::stringstream stream(s1 + " " + s2);
    std::unordered_map<std::string, int> counter;
    for (std::string word; stream >> word;) {
      ++counter[word];
    }

    std::vector<std::string> uncommon;
    for (const auto &[word, frequency] : counter) {
      if (frequency == 1) {
        uncommon.push_back(word);
      }
    }
    return uncommon;
  }
};
