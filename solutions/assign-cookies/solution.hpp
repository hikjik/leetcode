#pragma once

#include <algorithm>
#include <vector>

/*
  455. Assign Cookies
  https://leetcode.com/problems/assign-cookies/
  Difficulty: Easy
  Tags: Array, Two Pointers, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int findContentChildren(std::vector<int> g, std::vector<int> s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    size_t i = 0;
    for (size_t j = 0; i < g.size() && j < s.size(); ++j) {
      i += g[i] <= s[j];
    }
    return i;
  }
};
