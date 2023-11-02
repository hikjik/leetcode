#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string>
  stringMatching(std::vector<std::string> words) {
    std::vector<std::string> ans;
    for (const auto &w1 : words) {
      for (const auto &w2 : words) {
        if (w1.size() < w2.size() && w2.find(w1) != std::string::npos) {
          ans.push_back(w1);
          break;
        }
      }
    }
    return ans;
  }
};
