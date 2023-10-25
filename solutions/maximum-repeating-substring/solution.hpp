#pragma once

#include <string>

class Solution {
public:
  static int maxRepeating(std::string sequence, std::string word) {
    int ans = 0;
    for (auto s = word; sequence.find(s) != std::string::npos; s += word) {
      ++ans;
    }
    return ans;
  }
};
