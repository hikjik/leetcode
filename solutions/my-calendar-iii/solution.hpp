#pragma once

#include <map>

// Time:
// Space:

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
