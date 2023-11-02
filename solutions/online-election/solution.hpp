#pragma once

#include <map>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class TopVotedCandidate {
private:
  std::map<int, int> election_leaders;

public:
  TopVotedCandidate(const std::vector<int> &persons,
                    const std::vector<int> &times) {
    std::unordered_map<int, int> frequencies;
    int max_frequency = 0;
    for (size_t i = 0; i < persons.size(); ++i) {
      if (++frequencies[persons[i]] >= max_frequency) {
        election_leaders[times[i]] = persons[i];
        max_frequency = frequencies[persons[i]];
      }
    }
  }

  int q(int t) {
    auto ub = election_leaders.upper_bound(t);
    return std::prev(ub)->second;
  }
};
