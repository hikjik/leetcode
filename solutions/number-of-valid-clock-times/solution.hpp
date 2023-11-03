#pragma once

#include <regex>
#include <string>

// Time:
// Space:

class Solution {
public:
  static int countTime(std::string time) {
    return countHours(time.substr(0, 2)) * countMinutes(time.substr(3, 2));
  }

private:
  static int countHours(std::string hours) {
    if (hours == "??") {
      return 24;
    }
    if (hours[0] == '?') {
      return hours[1] < '4' ? 3 : 2;
    }
    if (hours[1] == '?') {
      return hours[0] < '2' ? 10 : 4;
    }
    return 1;
  }

  static int countMinutes(std::string minutes) {
    if (minutes == "??") {
      return 60;
    }
    if (minutes[0] == '?') {
      return 6;
    }
    if (minutes[1] == '?') {
      return 10;
    }
    return 1;
  }
};
