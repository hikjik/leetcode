#pragma once

#include <vector>

/*
  1299. Replace Elements with Greatest Element on Right Side
  https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> replaceElements(const std::vector<int> &arr) {
    std::vector<int> ans(arr.size());
    for (int i = arr.size() - 1, max = -1; i >= 0; --i) {
      ans[i] = max;
      max = std::max(max, arr[i]);
    }
    return ans;
  }
};
