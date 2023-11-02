#pragma once

#include <map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::vector<int>>
  mergeSimilarItems(const std::vector<std::vector<int>> &items1,
                    const std::vector<std::vector<int>> &items2) {
    std::map<int, int> map;
    for (const auto &items : {items1, items2}) {
      for (const auto &item : items) {
        map[item[0]] += item[1];
      }
    }

    std::vector<std::vector<int>> ans;
    for (const auto &[value, weight] : map) {
      ans.push_back({value, weight});
    }
    return ans;
  }
};
