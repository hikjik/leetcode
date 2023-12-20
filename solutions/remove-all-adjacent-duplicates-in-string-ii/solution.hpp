#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string removeDuplicates(std::string s, int k) {
    std::vector<std::pair<char, int>> stack;
    for (auto c : s) {
      if (stack.empty() || stack.back().first != c) {
        stack.push_back({c, 0});
      }
      if (++stack.back().second == k) {
        stack.pop_back();
      }
    }

    std::string ans;
    for (const auto &[c, cnt] : stack) {
      ans.append(cnt, c);
    }
    return ans;
  }
};
