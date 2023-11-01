#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2418. Sort the People
  https://leetcode.com/problems/sort-the-people/
  Difficulty: Easy
  Tags: Array, Hash Table, String, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  sortPeople(const std::vector<std::string> &names,
             const std::vector<int> &heights) {
    std::vector<std::pair<int, std::string>> people;
    for (size_t i = 0; i < names.size(); ++i) {
      people.push_back({heights[i], names[i]});
    }

    std::sort(people.begin(), people.end(), std::greater<>());

    std::vector<std::string> ans;
    for (const auto &[_, name] : people) {
      ans.push_back(name);
    }
    return ans;
  }
};
