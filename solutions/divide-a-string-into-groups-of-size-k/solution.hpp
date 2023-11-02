#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string> divideString(std::string s, int k,
                                               char fill) {
    s.resize((s.size() + k - 1) / k * k, fill);
    std::vector<std::string> ans;
    for (size_t i = 0; i < s.size(); i += k) {
      ans.push_back(s.substr(i, k));
    }
    return ans;
  }
};
