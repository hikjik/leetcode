#pragma once

#include <algorithm>
#include <vector>

/*
  826. Most Profit Assigning Work
  https://leetcode.com/problems/most-profit-assigning-work/
  Difficulty: Medium
  Tags: Array, Two Pointers, Binary Search, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int maxProfitAssignment(const std::vector<int> &difficulty,
                                 const std::vector<int> &profit,
                                 std::vector<int> workers) {
    std::vector<std::pair<int, int>> jobs;
    for (size_t i = 0; i < difficulty.size(); ++i) {
      jobs.push_back({difficulty[i], profit[i]});
    }

    std::sort(jobs.begin(), jobs.end());
    std::sort(workers.begin(), workers.end());

    int max_profit = 0, worker_profit = 0;
    size_t i = 0;
    for (auto worker : workers) {
      while (i < jobs.size() && jobs[i].first <= worker) {
        worker_profit = std::max(worker_profit, jobs[i].second);
        i++;
      }
      max_profit += worker_profit;
    }

    return max_profit;
  }
};
