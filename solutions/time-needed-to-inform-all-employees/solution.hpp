#pragma once

#include <queue>
#include <vector>

class Solution {
private:
  static int dfs(int i, const std::vector<int> &manager,
                 const std::vector<int> &inform_time, std::vector<int> *time) {
    if ((*time)[i] == -1) {
      (*time)[i] =
          inform_time[manager[i]] + dfs(manager[i], manager, inform_time, time);
    }
    return (*time)[i];
  }

public:
  static int numOfMinutes(int n, int head_id, const std::vector<int> &manager,
                          const std::vector<int> &inform_time) {
    std::vector<int> time(n, -1);
    time[head_id] = 0;

    int min_time = 0;
    for (int i = 0; i < n; ++i) {
      const auto t = dfs(i, manager, inform_time, &time);
      min_time = std::max(min_time, t);
    }

    return min_time;
  }
};
