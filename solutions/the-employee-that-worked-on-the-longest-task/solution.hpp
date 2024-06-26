#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int hardestWorker(int n, const std::vector<std::vector<int>> &logs) {
    int worker_id = n;
    int max_time = 0, time = 0;
    for (const auto &log : logs) {
      if (log[1] - time > max_time) {
        worker_id = log[0];
        max_time = log[1] - time;
      } else if (log[1] - time == max_time) {
        worker_id = std::min(worker_id, log[0]);
      }
      time = log[1];
    }
    return worker_id;
  }
};
