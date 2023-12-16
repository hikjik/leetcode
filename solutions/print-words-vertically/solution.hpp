#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<std::string> printVertically(std::string s) {
    std::vector<std::string> ans;
    for (int i = 0; auto c : s) {
      if (c == ' ') {
        i = 0;
      } else {
        if (i == std::ssize(ans)) {
          ans.emplace_back();
        }
        if (i) {
          const auto pad = ans[i - 1].size() - ans[i].size() - 1;
          ans[i].insert(ans[i].end(), pad, ' ');
        }
        ans[i++] += c;
      }
    }
    return ans;
  }
};
