#pragma once

#include <array>
#include <sstream>
#include <string>

// Time:
// Space:

class Solution {
public:
  static int countDaysTogether(std::string arriveAlice, std::string leaveAlice,
                               std::string arriveBob, std::string leaveBob) {
    const auto alice = getInterval(arriveAlice, leaveAlice);
    const auto bob = getInterval(arriveBob, leaveBob);

    if (alice.second < bob.first || bob.second < alice.first) {
      return 0;
    }

    return std::min(alice.second, bob.second) -
           std::max(alice.first, bob.first) + 1;
  }

private:
  static std::pair<int, int> getInterval(std::string arrive,
                                         std::string leave) {
    return {getDay(arrive), getDay(leave)};
  }

  static int getDay(std::string str) {
    static const std::array<int, 12> days{31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};

    std::stringstream stream(str);
    char c;
    int day, month;
    stream >> month >> c >> day;
    return std::accumulate(days.begin(), days.begin() + month - 1, 0) + day;
  }
};
