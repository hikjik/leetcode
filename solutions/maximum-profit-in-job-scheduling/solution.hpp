#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
private:
  struct Job {
    Job(int startTime, int endTime, int profit)
        : startTime(startTime), endTime(endTime), profit(profit) {}

    int startTime;
    int endTime;
    int profit;
  };

public:
  static int jobScheduling(const std::vector<int> &startTime,
                           const std::vector<int> &endTime,
                           const std::vector<int> &profit) {
    const int n = startTime.size();

    std::vector<Job> jobs;
    for (int i = 0; i < n; ++i) {
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);
    }

    std::sort(jobs.begin(), jobs.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.startTime < rhs.startTime;
    });

    std::vector<int> dp(n);
    return jobScheduling(0, jobs, &dp);
  }

private:
  static int jobScheduling(size_t i, const std::vector<Job> &jobs,
                           std::vector<int> *dp) {
    if (i == jobs.size()) {
      return 0;
    }

    auto &profit = (*dp)[i];
    if (profit) {
      return profit;
    }

    auto lb = std::lower_bound(
        jobs.begin() + i + 1, jobs.end(), jobs[i].endTime,
        [](const Job &job, int endTime) { return job.startTime < endTime; });
    const auto j = std::distance(jobs.begin(), lb);

    profit = std::max(jobScheduling(i + 1, jobs, dp),
                      jobScheduling(j, jobs, dp) + jobs[i].profit);
    return profit;
  }
};
