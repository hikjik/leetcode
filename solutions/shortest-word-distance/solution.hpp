#pragma once

#include <cmath>
#include <string>
#include <vector>

// N = wordsDict.size()
// K = word.size()
// Time: O(NK)
// Space: O(1)

class Solution {
public:
  static int shortestDistance(const std::vector<std::string> &wordsDict,
                              std::string word1, std::string word2) {
    int i1 = -1, i2 = -1;
    int ans = wordsDict.size();
    for (int i = 0; i < std::ssize(wordsDict); ++i) {
      if (wordsDict[i] == word1) {
        i1 = i;
      } else if (wordsDict[i] == word2) {
        i2 = i;
      }
      if (i1 != -1 && i2 != -1) {
        ans = std::min(ans, std::abs(i1 - i2));
      }
    }
    return ans;
  }
};
