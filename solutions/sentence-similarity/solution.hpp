#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// M = similarPairs.size()
// N = sentence1.size()
// K max word size
// Time: O(MK+NK)
// Space: O(M)

class Solution {
public:
  static bool areSentencesSimilar(
      const std::vector<std::string> &sentence1,
      const std::vector<std::string> &sentence2,
      const std::vector<std::vector<std::string>> &similarPairs) {
    if (sentence1.size() != sentence2.size()) {
      return false;
    }

    std::unordered_map<std::string_view, std::unordered_set<std::string_view>>
        map;
    for (const auto &pair : similarPairs) {
      map[pair[0]].insert(pair[1]);
      map[pair[1]].insert(pair[0]);
    }

    for (int i = 0; i < std::ssize(sentence1); ++i) {
      if (sentence1[i] != sentence2[i] &&
          !map[sentence1[i]].contains(sentence2[i])) {
        return false;
      }
    }
    return true;
  }
};
