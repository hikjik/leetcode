#pragma once

#include <string>
#include <string_view>
#include <vector>

// M = max(a.size(), b.size())
// Time: O(NM)
// Space: O(1)

class Solution {
public:
  static std::vector<int> beautifulIndices(std::string s, std::string a,
                                           std::string b, int k) {
    const std::string_view sv(s);
    std::vector<int> ans;
    for (size_t i = 0, j = 0; i + a.size() <= sv.size(); ++i) {
      if (sv.substr(i, a.size()) != a) {
        continue;
      }
      while (j + b.size() <= sv.size() && j <= i + k) {
        if (j + k >= i && sv.substr(j, b.size()) == b) {
          ans.push_back(i);
          break;
        }
        ++j;
      }
    }
    return ans;
  }
};
