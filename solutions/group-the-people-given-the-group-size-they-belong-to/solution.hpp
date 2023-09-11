#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  groupThePeople(const std::vector<int> &groupSizes) {
    std::vector<std::vector<int>> groups;
    std::unordered_map<int, std::vector<int>> map;
    for (size_t i = 0; i < groupSizes.size(); ++i) {
      auto &group = map[groupSizes[i]];
      group.push_back(i);
      if (group.size() == groupSizes[i] * 1UL) {
        groups.push_back(std::move(group));
        group.clear();
      }
    }
    return groups;
  }
};
