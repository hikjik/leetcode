#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::string mostCommonWord(std::string paragraph,
                                    const std::vector<std::string> &banned) {
    for (auto &c : paragraph) {
      c = std::isalpha(c) ? std::tolower(c) : ' ';
    }

    std::unordered_set<std::string> banned_set(banned.begin(), banned.end());
    std::unordered_map<std::string, int> counter;
    std::stringstream stream(paragraph);
    for (std::string word; stream >> word;) {
      if (!banned_set.contains(word)) {
        ++counter[word];
      }
    }

    return std::max_element(counter.begin(), counter.end(),
                            [](const auto &lhs, const auto &rhs) {
                              return lhs.second < rhs.second;
                            })
        ->first;
  }
};
