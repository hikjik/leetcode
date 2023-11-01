#pragma once

#include <string>

/*
  1945. Sum of Digits of String After Convert
  https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
  Difficulty: Easy
  Tags: String, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int getLucky(std::string s, int k) {
    auto number = convert(s);
    while (k--) {
      number = digitsSum(number);
    }
    return std::stoi(number);
  }

private:
  static std::string convert(const std::string &s) {
    std::string number;
    for (auto c : s) {
      number += std::to_string(c - 'a' + 1);
    }
    return number;
  }

  static std::string digitsSum(const std::string &s) {
    int sum = 0;
    for (auto c : s) {
      sum += c - '0';
    }
    return std::to_string(sum);
  }
};
