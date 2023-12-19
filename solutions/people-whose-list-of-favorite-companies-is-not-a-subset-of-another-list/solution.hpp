#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// N = favoriteCompanies.size()
// M = favoriteCompanies[i].size()
// K = favoriteCompanies[i][j].size()
// Time: O(N^2MK)
// Space: O(NM)

class Solution {
public:
  static std::vector<int> peopleIndexes(
      const std::vector<std::vector<std::string>> &favoriteCompanies) {
    const int n = favoriteCompanies.size();
    std::vector<std::unordered_set<std::string_view>> sets;
    for (const auto &companies : favoriteCompanies) {
      sets.emplace_back(companies.begin(), companies.end());
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      bool notSubset = true;
      for (int j = 0; j < n && notSubset; ++j) {
        if (i != j && sets[j].size() > sets[i].size()) {
          notSubset &= std::ranges::any_of(
              favoriteCompanies[i],
              [&](const auto &company) { return !sets[j].contains(company); });
        }
      }
      if (notSubset) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
