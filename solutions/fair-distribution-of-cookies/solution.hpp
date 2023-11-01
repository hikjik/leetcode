#pragma once

#include <algorithm>
#include <limits>
#include <vector>

/*
  2305. Fair Distribution of Cookies
  https://leetcode.com/problems/fair-distribution-of-cookies/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Backtracking, Bit Manipulation, Bitmask
  Time:
  Space:
*/

class Solution {
public:
  static int distributeCookies(const std::vector<int> &cookies, int k) {
    std::vector<int> children(k);
    int ans = std::numeric_limits<int>::max();
    distributeCookies(0, cookies, &children, &ans);
    return ans;
  }

private:
  static void distributeCookies(size_t i, const std::vector<int> &cookies,
                                std::vector<int> *children, int *ans) {
    if (i == cookies.size()) {
      *ans =
          std::min(*std::max_element(children->begin(), children->end()), *ans);
      return;
    }

    for (auto &child : *children) {
      child += cookies[i];
      distributeCookies(i + 1, cookies, children, ans);
      child -= cookies[i];

      if (!child) {
        break;
      }
    }
  }
};
