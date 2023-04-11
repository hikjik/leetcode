#pragma once

#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> avoidFlood(const std::vector<int> &rains) {
    std::vector<int> ans(rains.size(), -1);

    std::unordered_map<int, int> full_lakes;
    std::set<int> dry_days;

    for (size_t i = 0; i < rains.size(); ++i) {
      if (!rains[i]) {
        dry_days.insert(i);
        continue;
      }

      if (auto it = full_lakes.find(rains[i]); it != full_lakes.end()) {
        auto lb = dry_days.lower_bound(it->second);
        if (lb == dry_days.end()) {
          return {};
        }
        ans[*lb] = it->first;
        dry_days.erase(lb);
      }
      full_lakes[rains[i]] = i;
    }

    for (const int day : dry_days) {
      ans[day] = 1;
    }

    return ans;
  }
};
