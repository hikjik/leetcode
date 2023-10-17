#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static bool haveConflict(const std::vector<std::string> &event1,
                           const std::vector<std::string> &event2) {
    return hasIntersection(getInterval(event1), getInterval(event2));
  }

private:
  static bool hasIntersection(const std::pair<int, int> &event1,
                              const std::pair<int, int> &event2) {
    if (event1.second < event2.first || event2.second < event1.first) {
      return false;
    }
    return std::min(event1.second, event2.second) >=
           std::max(event1.first, event2.first);
  }

  static std::pair<int, int>
  getInterval(const std::vector<std::string> &event) {
    return {getMinutes(event[0]), getMinutes(event[1])};
  }

  static int getMinutes(std::string time) {
    const int h = (time[0] - '0') * 10 + time[1] - '0';
    const int m = (time[3] - '0') * 10 + time[4] - '0';
    return h * 60 + m;
  }
};
