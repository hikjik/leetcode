#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> repeated;
    std::unordered_map<std::string, int> counter;
    for (size_t i = 0; i + 9 < s.size(); ++i) {
      if (++counter[s.substr(i, 10)] == 2) {
        repeated.push_back(s.substr(i, 10));
      }
    }
    return repeated;
  }
};
