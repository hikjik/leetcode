#pragma once

#include <algorithm>
#include <vector>

/*
  1601. Maximum Number of Achievable Transfer Requests
  https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
  Difficulty: Hard
  Tags: Array, Backtracking, Bit Manipulation, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static int maximumRequests(int n,
                             const std::vector<std::vector<int>> &requests) {
    std::vector<int> buildings(n);
    int max_requests = 0;
    maximumRequests(0, 0, requests, &buildings, &max_requests);
    return max_requests;
  }

private:
  static void maximumRequests(size_t i, int cnt,
                              const std::vector<std::vector<int>> &requests,
                              std::vector<int> *buildings, int *max_requests) {
    if (i == requests.size()) {
      if (std::all_of(buildings->begin(), buildings->end(),
                      [](int i) { return !i; })) {
        *max_requests = std::max(*max_requests, cnt);
      }
      return;
    }

    maximumRequests(i + 1, cnt, requests, buildings, max_requests);
    const auto from = requests[i][0], to = requests[i][1];
    --(*buildings)[from], ++(*buildings)[to];
    maximumRequests(i + 1, cnt + 1, requests, buildings, max_requests);
    ++(*buildings)[from], --(*buildings)[to];
  }
};
