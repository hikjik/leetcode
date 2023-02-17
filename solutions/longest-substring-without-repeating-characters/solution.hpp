#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  static int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, size_t> letters;
    size_t start = 0;
    size_t length = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (letters.count(s[i])) {
        start = std::max(start, letters[s[i]] + 1);
      }
      letters[s[i]] = i;
      length = std::max(length, i - start + 1);
    }
    return length;
  }
};
