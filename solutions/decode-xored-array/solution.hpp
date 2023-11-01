#pragma once

#include <vector>

/*
  1720. Decode XORed Array
  https://leetcode.com/problems/decode-xored-array/
  Difficulty: Easy
  Tags: Array, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> decode(const std::vector<int> &encoded, int first) {
    std::vector<int> arr{first};
    for (auto a : encoded) {
      arr.push_back(a ^ arr.back());
    }
    return arr;
  }
};
