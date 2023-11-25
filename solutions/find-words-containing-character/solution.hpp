#pragma once

#include <string>
#include <vector>

// Time: O(NM), N is the number of words, M is the max length of word
// Space: O(1)

class Solution {
public:
  static std::vector<int>
  findWordsContaining(const std::vector<std::string> &words, char x) {
    std::vector<int> ans;
    for (int i = 0; i < std::ssize(words); ++i) {
      if (words[i].find(x) != std::string::npos) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
