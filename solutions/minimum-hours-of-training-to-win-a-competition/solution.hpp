#pragma once

#include <numeric>
#include <vector>

/*
  2383. Minimum Hours of Training to Win a Competition
  https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
  Difficulty: Easy
  Tags: Array, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static int minNumberOfHours(int initialEnergy, int initialExperience,
                              const std::vector<int> &energy,
                              const std::vector<int> &experience) {
    return trainEnergy(initialEnergy, energy) +
           trainExperience(initialExperience, experience);
  }

private:
  static int trainEnergy(int initialEnergy, const std::vector<int> &energy) {
    const auto sum = std::accumulate(energy.begin(), energy.end(), 0);
    return std::max(0, sum - initialEnergy + 1);
  }

  static int trainExperience(int initialExperience,
                             const std::vector<int> &experience) {
    int max = 0, prev = 0;
    for (auto e : experience) {
      max = std::max(max, e - prev);
      prev += e;
    }
    return std::max(0, max - initialExperience + 1);
  }
};
