#pragma once

#include <unordered_map>
#include <vector>

/*
  1282. Group the People Given the Group Size They Belong To
  https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
  Difficulty: Medium
  Tags: Array, Hash Table
  Time:
  Space:
*/

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
