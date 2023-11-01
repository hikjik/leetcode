#pragma once

#include <map>

/*
  732. My Calendar III
  https://leetcode.com/problems/my-calendar-iii/
  Difficulty: Hard
  Tags: Binary Search, Design, Segment Tree, Ordered Set
  Time:
  Space:
*/

class MyCalendarThree {
private:
  std::map<int, int> map;

public:
  int book(int start, int end) {
    map[start]++, map[end]--;
    int max_book = 0, cnt = 0;
    for (const auto &[_, t] : map) {
      max_book = std::max(max_book, cnt += t);
    }
    return max_book;
  }
};
