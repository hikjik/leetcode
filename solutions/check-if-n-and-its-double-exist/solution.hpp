#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  static bool checkIfExist(const std::vector<int> &arr) {
    std::unordered_set<int> seen;
    for (auto a : arr) {
      if (seen.count(2 * a) || a % 2 == 0 && seen.count(a / 2)) {
        return true;
      }
      seen.insert(a);
    }
    return false;
  }
};
