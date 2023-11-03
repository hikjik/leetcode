#pragma once

#include <string>
#include <unordered_set>

// Time:
// Space:

class Solution {
public:
  static int numDifferentIntegers(std::string word) {
    std::unordered_set<std::string> set;
    for (auto first = word.begin(); first != word.end();) {
      if (!std::isdigit(*first)) {
        ++first;
      } else {
        auto last = std::find_if(first, word.end(),
                                 [](char c) { return !std::isdigit(c); });
        while (first != std::prev(last) && *first == '0') {
          ++first;
        }
        set.emplace(first, last);
        first = last;
      }
    }
    return set.size();
  }
};
