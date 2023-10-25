#pragma once

#include <vector>

class Solution {
public:
  static int countStudents(const std::vector<int> &students,
                           const std::vector<int> &sandwiches) {
    std::vector<int> cnt(2);
    for (auto s : students) {
      ++cnt[s];
    }

    for (auto s : sandwiches) {
      if (!cnt[s]) {
        break;
      }
      --cnt[s];
    }

    return cnt[0] + cnt[1];
  }
};
