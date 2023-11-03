#pragma once

#include <set>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool buddyStrings(std::string s, std::string goal) {
    if (s.size() != goal.size()) {
      return false;
    }

    if (s == goal && std::set<int>(s.begin(), s.end()).size() != s.size()) {
      return true;
    }

    std::vector<int> indexes;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] != goal[i]) {
        indexes.push_back(i);
        if (indexes.size() > 2) {
          break;
        }
      }
    }

    return indexes.size() == 2 && s[indexes[0]] == goal[indexes[1]] &&
           s[indexes[1]] == goal[indexes[0]];
  }
};
