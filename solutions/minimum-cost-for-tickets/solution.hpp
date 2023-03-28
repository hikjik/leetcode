#pragma once

#include <vector>

class Solution {
public:
  static int mincostTickets(const std::vector<int> &days,
                            const std::vector<int> &costs) {
    std::vector<bool> is_travel_day(366, 0);
    for (auto d : days) {
      is_travel_day[d] = true;
    }

    std::vector<int> dp(366, -1);

    return mincost(1, costs, is_travel_day, &dp);
  }

private:
  static int mincost(int day, const std::vector<int> &costs,
                     const std::vector<bool> &is_travel_day,
                     std::vector<int> *dp) {
    if (day >= 366) {
      return 0;
    }

    auto &cost = (*dp)[day];
    if (cost != -1) {
      return cost;
    }
    if (is_travel_day[day]) {
      cost = std::min({
          mincost(day + 1, costs, is_travel_day, dp) + costs[0],
          mincost(day + 7, costs, is_travel_day, dp) + costs[1],
          mincost(day + 30, costs, is_travel_day, dp) + costs[2],
      });
    } else {
      cost = mincost(day + 1, costs, is_travel_day, dp);
    }
    return cost;
  }
};
