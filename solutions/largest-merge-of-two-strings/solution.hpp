#pragma once

#include <ranges>
#include <string>

// Time: O(N^2+M^2)
// Space: O(1)

class Solution {
public:
  static std::string largestMerge(std::string w1, std::string w2) {
    std::string ans;
    for (auto it1 = w1.begin(), it2 = w2.begin();
         it1 != w1.end() || it2 != w2.end();) {
      if (std::lexicographical_compare(it1, w1.end(), it2, w2.end())) {
        ans += *it2++;
      } else {
        ans += *it1++;
      }
    }
    return ans;
  }
};
