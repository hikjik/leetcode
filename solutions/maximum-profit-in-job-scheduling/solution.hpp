#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

namespace memo {

// Time: O(NlogN)
// Space: O(N)
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

    std::ranges::sort(jobs, [](const auto &lhs, const auto &rhs) {
      return lhs.startTime < rhs.startTime;
    });

    std::vector<int> memo(n);
    return jobScheduling(0, jobs, &memo);
  }

private:
  static int jobScheduling(int i, const std::vector<Job> &jobs,
                           std::vector<int> *memo) {
    if (i == std::ssize(jobs)) {
      return 0;
    }
    auto &profit = (*memo)[i];
    if (!profit) {
      const int j = std::distance(
          jobs.begin(),
          std::ranges::lower_bound(jobs, jobs[i].endTime, {}, &Job::startTime));
      profit = std::max(jobScheduling(i + 1, jobs, memo),
                        jobs[i].profit + jobScheduling(j, jobs, memo));
    }
    return profit;
  }
};

} // namespace memo

namespace dp {

// Time: O(NlogN)
// Space: O(N)
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

    std::ranges::sort(jobs, [](const auto &lhs, const auto &rhs) {
      return lhs.startTime < rhs.startTime;
    });

    std::vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      const int j = std::distance(
          jobs.begin(),
          std::ranges::lower_bound(jobs, jobs[i].endTime, {}, &Job::startTime));
      dp[i] = std::max(dp[i + 1], jobs[i].profit + dp[j]);
    }
    return dp[0];
  }
};

} // namespace dp
