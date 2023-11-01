#pragma once

#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

/*
  599. Minimum Index Sum of Two Lists
  https://leetcode.com/problems/minimum-index-sum-of-two-lists/
  Difficulty: Easy
  Tags: Array, Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  findRestaurant(const std::vector<std::string> &list1,
                 const std::vector<std::string> &list2) {
    std::unordered_map<std::string, int> map;
    for (int i = 0; i < std::ssize(list1); ++i) {
      map[list1[i]] = i;
    }

    std::vector<std::string> ans;
    int idx_sum = INT_MAX;
    for (int i = 0; i < std::ssize(list2); ++i) {
      if (auto it = map.find(list2[i]); it != map.end()) {
        if (ans.empty() || idx_sum > i + it->second) {
          ans = {list2[i]};
          idx_sum = i + it->second;
        } else if (idx_sum == i + it->second) {
          ans.push_back(list2[i]);
        }
      }
    }
    return ans;
  }
};
