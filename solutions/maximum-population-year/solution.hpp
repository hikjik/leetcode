#pragma once

#include <array>
#include <numeric>
#include <vector>

class Solution {
public:
  static constexpr int kMinYear = 1950, kMaxYear = 2050;
  static int maximumPopulation(const std::vector<std::vector<int>> &logs) {
    std::array<int, kMaxYear - kMinYear + 1> population{};
    for (const auto &log : logs) {
      ++population[log[0] - kMinYear];
      --population[log[1] - kMinYear];
    }
    std::partial_sum(population.begin(), population.end(), population.begin());
    const auto max = std::max_element(population.begin(), population.end());
    return kMinYear + std::distance(population.begin(), max);
  }
};
