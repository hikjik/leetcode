#pragma once

#include <map>
#include <vector>

class Solution {
public:
  static std::vector<int> relativeSortArray(const std::vector<int> &arr1,
                                            const std::vector<int> &arr2) {
    std::map<int, int> map;
    for (auto a : arr1) {
      ++map[a];
    }

    std::vector<int> ans;
    for (auto a : arr2) {
      ans.insert(ans.end(), map[a], a);
      map.erase(a);
    }
    for (const auto &[a, f] : map) {
      ans.insert(ans.end(), f, a);
    }
    return ans;
  }
};
