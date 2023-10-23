#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string restoreString(std::string s,
                                   const std::vector<int> &indices) {
    std::string ans(s);
    for (size_t i = 0; i < indices.size(); ++i) {
      ans[indices[i]] = s[i];
    }
    return ans;
  }
};
