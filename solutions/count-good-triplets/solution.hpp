#pragma once

#include <cmath>
#include <vector>

/*
  1534. Count Good Triplets
  https://leetcode.com/problems/count-good-triplets/
  Difficulty: Easy
  Tags: Array, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static int countGoodTriplets(const std::vector<int> &arr, int a, int b,
                               int c) {
    int cnt = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
      for (size_t j = i + 1; j < arr.size(); ++j) {
        if (std::abs(arr[i] - arr[j]) <= a) {
          for (size_t k = j + 1; k < arr.size(); ++k) {
            cnt += std::abs(arr[j] - arr[k]) <= b &&
                   std::abs(arr[i] - arr[k]) <= c;
          }
        }
      }
    }
    return cnt;
  }
};
