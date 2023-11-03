#pragma once

#include <numeric>
#include <string>

// Time:
// Space:

class Solution {
public:
  static char findTheDifference(std::string s, std::string t) {
    return std::accumulate(t.begin(), t.end(), 0) -
           std::accumulate(s.begin(), s.end(), 0);
  }
};
