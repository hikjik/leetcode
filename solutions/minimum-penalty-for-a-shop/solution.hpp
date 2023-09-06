#pragma once

#include <algorithm>
#include <string>

class Solution {
public:
  static int bestClosingTime(std::string customers) {
    int closing_time = 0;
    int max_profit = 0, profit = 0;
    for (size_t i = 0; i < customers.size(); ++i) {
      profit += customers[i] == 'Y' ? 1 : -1;
      if (profit > max_profit) {
        max_profit = profit;
        closing_time = i + 1;
      }
    }
    return closing_time;
  }
};
