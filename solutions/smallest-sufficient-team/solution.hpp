#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int>
  smallestSufficientTeam(const std::vector<std::string> &req_skills,
                         const std::vector<std::vector<std::string>> &people) {
    std::unordered_map<std::string, int> skills_ids;
    for (size_t i = 0; i < req_skills.size(); ++i) {
      skills_ids[req_skills[i]] = i;
    }

    std::vector<int> person_skills_mask(people.size(), 0);
    for (size_t i = 0; i < people.size(); ++i) {
      for (const auto &skill : people[i]) {
        person_skills_mask[i] |= 1 << skills_ids[skill];
      }
    }

    std::vector<long long> dp(1 << req_skills.size(),
                              (1LL << people.size()) - 1);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << req_skills.size()); ++mask) {
      for (size_t i = 0; i < people.size(); ++i) {
        const auto thin_mask = ~person_skills_mask[i] & mask;
        if (__builtin_popcountll(dp[thin_mask]) + 1 <
            __builtin_popcountll(dp[mask])) {
          dp[mask] = dp[thin_mask] | (1LL << i);
        }
      }
    }

    std::vector<int> sufficient_team;
    const auto sufficient_team_mask = dp.back();
    for (size_t i = 0; i < people.size(); ++i) {
      if ((sufficient_team_mask >> i) & 1) {
        sufficient_team.push_back(i);
      }
    }
    return sufficient_team;
  }
};
