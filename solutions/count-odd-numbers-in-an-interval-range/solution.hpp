#pragma once

/*
  1523. Count Odd Numbers in an Interval Range
  https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static int countOdds(int low, int high) { return (high + 1) / 2 - low / 2; }
};
