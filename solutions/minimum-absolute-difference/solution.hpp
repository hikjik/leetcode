#pragma once

#include <algorithm>
#include <climits>
#include <vector>

/*
  1200. Minimum Absolute Difference
  https://leetcode.com/problems/minimum-absolute-difference/
  Difficulty: Easy
  Tags: Array, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>>
  minimumAbsDifference(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> ans;
    for (int i = 1, diff = INT_MAX; i < std::ssize(arr); ++i) {
      if (arr[i] - arr[i - 1] < diff) {
        diff = arr[i] - arr[i - 1];
        ans = {{arr[i - 1], arr[i]}};
      } else if (arr[i] - arr[i - 1] == diff) {
        ans.push_back({arr[i - 1], arr[i]});
      }
    }
    return ans;
  }
};
