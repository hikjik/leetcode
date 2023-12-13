#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> maxDepthAfterSplit(std::string seq) {
    std::vector<int> ans;
    for (int depth = 0; auto c : seq) {
      ans.push_back(c == '(' ? depth++ & 1 : --depth & 1);
    }
    return ans;
  }
};
