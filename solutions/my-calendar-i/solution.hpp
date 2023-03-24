#pragma once

#include <map>

class MyCalendar {
public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto lb = calendar_.lower_bound(end);
    if (lb == calendar_.begin() || (--lb)->second <= start) {
      calendar_[start] = end;
      return true;
    }
    return false;
  }

private:
  std::map<int, int> calendar_;
};
