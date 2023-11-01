#pragma once

#include <vector>

/*
  1437. Check If All 1's Are at Least Length K Places Away
  https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool kLengthApart(const std::vector<int> &nums, int k) {
    for (int distance = 0; auto num : nums) {
      if (!num) {
        --distance;
      } else {
        if (distance > 0) {
          return false;
        }
        distance = k;
      }
    }
    return true;
  }
};
